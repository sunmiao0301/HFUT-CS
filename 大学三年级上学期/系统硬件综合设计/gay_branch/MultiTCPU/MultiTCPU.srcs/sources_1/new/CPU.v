`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/12/11 18:57:59
// Design Name: 
// Module Name: CPU
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

module CPU(
    input clk0,                     //100MHZ ,控制数码管亮,到时候和p17引脚连  
    input clk,                    
    input res,
    output wire[2:0] presentState,
    output wire[6:0] a_to_g_0,                    //数码管输出，低16位
    output wire[6:0] a_to_g_1,                    //高16位
    output wire [31:0] pcAddr,
    output wire[7:0] an);
    
                    
    wire [31:0] ADR_out;
    wire [31:0] BDR_out;
    wire [31:0] DBDR_out;
    wire [31:0] instruction;
    wire [31:0] Read1, Read2, result, DataOut;
    wire [31:0] ExtOut;		                                       //扩展的输出
    wire [31:0] JumpAddr;
    wire [31:0] ALUDR_out;
    
    wire [1:0] PCSrc;
    wire [3:0] ALUOp;
    wire PCWre,InsMemRead,RegRead,RegWr,MemToReg,RegDes,ALUSrcA, ALUSrcB,bcon,MemRead, MemWrite, ExtSel;
    
    // PC 
    PC pc0 (.res(res), .PCWre(PCWre), .PCSrc(PCSrc), .addr(JumpAddr), .imm(ExtOut), .Reg(Read1), .pc1(pcAddr));

  	// Reg
    Reg reg0 (.RegRead(RegRead),.RegWr(RegWr),.MemToReg(MemToReg),.rs(instruction [25:21]), .rt(instruction [20:16]), .rd(instruction [15:11]), .RegDes(RegDes), .DataALU(ALUDR_out), .DataMem(DBDR_out), .Read1(Read1), .Read2(Read2));
    Delay ADR (.in(Read1),.clk(clk),.out(ADR_out));
    Delay BDR (.in(Read2),.clk(clk),.out(BDR_out));

    // ALU                                               
    ALU alu(.Read1(ADR_out),.Read2(BDR_out),.imm(ExtOut),.ALUSrcA(ALUSrcA),.ALUSrcB(ALUSrcB),.sa(instruction [10:6]),.ALUOp(ALUOp),.bcon(bcon),.result(result));
    Delay ALUoutDR (.clk(clk), .in(result), .out(ALUDR_out));
    trans ALUx1(.x(ALUDR_out[31:16]),.clk (clk0),.rst (res) ,.a_to_g(a_to_g_1),.an(an[7:4]));
    trans ALUx0(.x(ALUDR_out[15:0]),.clk(clk0) ,.rst(res),.a_to_g(a_to_g_0) ,.an(an[3:0]));
    
    // DataMEM 
    DataMEM datamem (.MemRead(MemRead),.MemWrite(MemWrite), .Addr(ALUDR_out), .DataIn(BDR_out), .DataOut(DataOut));
    Delay DBDR (.clk(clk),.in(DataOut),.out(DBDR_out));
  
    // Extend
    Extend extend (.in(instruction [15:0]),.ExtSel(ExtSel),.out(ExtOut));

    // PCAddress 
    PCAddress pcaddress (.in_addr(instruction [25:0]), .PC0(pcAddr), .addr(JumpAddr));

    // InsMEM
    InsMem insmem (.clk(clk), .InsMemRead(InsMemRead), .addr(pcAddr), .ins(instruction));

    //CU
    CU cu (.clk(clk), .rst(res), .Opcode(instruction[31:26]),.func(instruction [5:0]), .PCWre(PCWre),
        .PCSrc(PCSrc),.InsMemRead(InsMemRead),.RegWr(RegWr), .RegRead(RegRead),.RegDes(RegDes),.bcon(bcon),.ALUSrcA(ALUSrcA),.ALUSrcB(ALUSrcB), .ALUOp(ALUOp),.MemToReg(MemToReg), 
         .MemRead(MemRead), .MemWrite(MemWrite), .ExtSel(ExtSel),.presentState(presentState));


endmodule


