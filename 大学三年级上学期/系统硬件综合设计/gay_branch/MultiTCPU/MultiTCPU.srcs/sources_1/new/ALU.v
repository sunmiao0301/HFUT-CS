`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/12/10 16:55:13
// Design Name: 
// Module Name: ALU
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


module ALU(
            input [31:0] Read1, Read2, imm,                                                         //imm需要经过扩展
            input ALUSrcA,
            input ALUSrcB,
            input [4:0] sa,                          
            input [3:0] ALUOp,
            output wire bcon,
            output reg [31:0] result);
	 
	 initial begin
        result = 0;
    end
 
    wire [31:0] A;
    wire [31:0] B;
    
    assign A[31:0] = ALUSrcA? sa[4:0] : Read1[31:0];                         //为1，就给sa，虽然sa为5位，但不会出错
    assign B[31:0] = ALUSrcB? imm[31:0] : Read2[31:0];
    assign bcon = (result? 0 : 1);                                //仅当分支指令时有效。是其判断结果，result=0代表两个相等，bcon=1
	 //ALU的计算不是靠CLK来触发的，所以在ALU的A和B之前再加个数据延迟器同步时钟信号
	 //A和B都是wire型，处理完一次之后不会保持原来的信号，都是一次性的
	always @(A or B) begin                                                                                                                                                                            
        case(ALUOp)                                            //由CU决定执行什么类型的操作（加、减、移位等），将对应的信号传给ALU执行
            4'b0000: result = A + B;                     //func的类别也由CU判断，ALU只管进行运算
            4'b0001: result = A - B;  
            4'b0010: result = A | B;  
            4'b0011: result = A & B;          
            4'b0100: result = A^B;                      //异或
            4'b0101: result = ~(A | B);                 //nor
            4'b0110: result = A << B;                  //sll, zero-extend
            4'b0111: result = A >> B;                  //srl
            4'b1000: result = (A < B ? 1 : 0);       //slt
        default: result = 0;
    endcase
    end
	 
endmodule


