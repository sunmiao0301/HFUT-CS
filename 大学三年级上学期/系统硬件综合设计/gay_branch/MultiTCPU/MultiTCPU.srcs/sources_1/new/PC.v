`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/12/08 21:06:24
// Design Name: 
// Module Name: PC
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
module PC(
    input res,
    input PCWre,
    input [1:0] PCSrc,
    input [31:0] addr,
    input [31:0] imm,
    input [31:0] Reg,
    output reg [31:0] pc1);                   //当前的PC

    reg [31:0] nextPC;

    initial begin
        pc1 <= 0;
        nextPC <= 0;                     //第一条指令未知，下一条PC不知道怎么取，所以设为0
    end
    
    always @(PCWre) begin
            if (res)  pc1 = 0;               //res为1要重置    
            else if (PCWre) begin
                pc1 = nextPC;
            end
        end

    always @(PCSrc or imm or addr or Reg) begin         //连续跳转也能有激励信号,不同的指令
         case(PCSrc)    //imm、addr、reg至少有一个会发生变化，所以连续的PC+4也能工作
                   2'b00: nextPC = pc1 + 4;
                   2'b01: nextPC = pc1 + 4 + imm * 4;                //来自寄存器的地址
                   2'b10: nextPC = Reg;                           //jump无条件跳转
                   2'b11: nextPC = addr;
          endcase
    end
    
endmodule
