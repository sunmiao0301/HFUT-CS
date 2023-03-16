`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/12/11 16:46:33
// Design Name: 
// Module Name: CU
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module CU(
        input clk,
        input rst,					     //为1表示重置CU
        input [5:0] Opcode,
        input [5:0] func,

        output reg PCWre,
        output reg [1:0] PCSrc,

        output reg InsMemRead,

        output reg RegRead,
        output reg RegWr,
        output reg RegDes,

        input bcon,
        output reg ALUSrcA,
        output reg ALUSrcB,
        output reg [3:0] ALUOp,

        output reg MemToReg,
        output reg MemRead,
        output reg MemWrite,

        output reg ExtSel,
        output reg[2:0] presentState);

        reg[2:0] nextState;

        parameter [2:0] IF = 3'b000,
                                    ID = 3'b001,
                                    EXE = 3'b010,
                                    MEM = 3'b011,
                                    WB = 3'b100;
    initial begin
            presentState<=IF;
            nextState<=ID;
    end

    always @(posedge clk) begin
        if (rst)begin					  //重置
                presentState<=IF;
        end
        else begin
            presentState <= nextState;
        end
    end
    
    parameter [5:0] add = 6'b000000,                        //func的
                 sub = 6'b000001,
                 move = 6'b000010,
                 Or = 6'b000011,
                 And = 6'b000100,
                 Xor = 6'b000101,
                 Nor = 6'b000110,
                 sll = 6'b001000,
                 srl = 6'b001001,
                 slt = 6'b001100,
                 jr = 6'b010000,
                 //接下来是op
                 addi = 6'b000001,
                 ori = 6'b000100,
                 andi = 6'b000101,
                 slti = 6'b001000,
                 sw = 6'b110000,
                 lw = 6'b110001,
                 beq = 6'b010000,
                 bne = 6'b010001,
                 j = 6'b011000,
                 halt = 6'b111111;

    //状态转换
    //add,sub,move,or,and,xor,nor,sll,srl,slt,addi,ori,andi,slti：if，id，ex，wb
    //lw：if，id，ex，mem，wb
    //sw：if，id，ex，mem
    //j,jr,halt：if，id
    //beq,bne：if，id，ex
    always @(presentState or Opcode or func) begin
        case (presentState)
            IF: nextState <= ID;
            ID: begin                                                   
                case (Opcode)
                    j,halt: begin
                        nextState <= IF;
                    end
                    default: nextState <= EXE;                     
                endcase
                if(func == jr)begin
                        nextState <= IF;
                end
            end
            EXE: begin
                case(Opcode)
                    beq,bne: begin
                        nextState <= IF;
                    end
                    sw,lw: begin
                        nextState <= MEM;
                    end
                    default: nextState <= WB;
                endcase
            end
            MEM: begin
                case (Opcode)
                    sw: nextState <= IF;
                    lw: nextState <= WB;
                endcase
            end
            WB: begin
                nextState <= IF;
            end
        endcase
    end

    //set all signals
    always @(presentState) begin
    // PCWre 
        if (presentState == IF) begin
            PCWre = 1;
            if(Opcode == halt)
                PCWre = 0;
        end
        else 
            PCWre = 0;
    // InsMemRead
        if (presentState == IF)             
            InsMemRead = 1;
        else
            InsMemRead = 0;
    // ALUSrcA
        if ((presentState == EXE) && (func == sll || func == srl))
            ALUSrcA = 1;
        else
            ALUSrcA = 0;
    // ALUSrcB
        if ((presentState == EXE) && (Opcode == addi || Opcode == ori || Opcode == slti || Opcode == lw || Opcode == sw || Opcode == andi))
            ALUSrcB = 1;
        else
            ALUSrcB = 0;
    // MemToReg
        if (Opcode == lw)
            MemToReg = 1;
        else
            MemToReg = 0;     
    //RegRead
         if (presentState == ID)
            RegRead = 1;
        else
            RegRead = 0;
    // RegWr
        if (presentState == WB)
            RegWr = 1;
        else
            RegWr = 0;
    // RegDes 
        if (Opcode == addi || Opcode == ori || Opcode == slti || Opcode == lw || Opcode == andi)
            RegDes = 1;
        else 
            RegDes = 0;
    //MemRead
        if (Opcode == lw)
            MemRead = 1;
        else
            MemRead = 0;
    //MemWrite
        if (presentState == MEM && Opcode == sw)
            MemWrite = 1;
        else
            MemWrite = 0;
    // ExtSel
        if (Opcode == addi || Opcode == lw || Opcode == sw || Opcode == beq || Opcode == bne || Opcode ==slti)
            ExtSel = 1;
        else
            ExtSel = 0;
    // PCSrc [1:0]
        if (Opcode == j)
            PCSrc = 2'b11;
        else if (func == jr)
            PCSrc = 2'b10;
        else if ((bcon == 1 && Opcode == beq) || ((bcon == 0 && Opcode == bne)))
            PCSrc = 2'b01;
        else
            PCSrc = 2'b00;

            
    // ALUOp [3:0]
        case(Opcode)
            addi,lw,sw:begin
                ALUOp = 4'b0000;
            end
            beq,bne: begin
                ALUOp = 4'b0001;
            end
            slti: ALUOp = 4'b1000;
            ori: ALUOp = 4'b0010;
            andi: ALUOp = 4'b0011;
            default: ALUOp = 4'b0000;
        endcase
        
        if(Opcode == 0)begin
            case(func)
                add,move:begin
                    ALUOp = 4'b0000;
                end
                sub: ALUOp = 4'b0001;
                Or: ALUOp = 4'b0010;
                And: ALUOp = 4'b0011;
                Xor: ALUOp = 4'b0100;
                Nor: ALUOp = 4'b0101;
                sll: ALUOp = 4'b0110;
                srl: ALUOp = 4'b0111;
                slt: ALUOp = 4'b1000;
                default: ALUOp = 4'b0000;
            endcase
        end
   end
endmodule
