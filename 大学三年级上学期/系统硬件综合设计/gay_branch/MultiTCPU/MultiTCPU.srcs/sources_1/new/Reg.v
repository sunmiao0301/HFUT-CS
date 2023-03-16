`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/12/08 21:36:49
// Design Name: 
// Module Name: Reg
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
module Reg(
        input RegRead, RegWr, MemToReg,
        input [4:0] rs, rt, rd,
        input RegDes,
        input [31:0] DataALU, DataMem,
        output reg [31:0] Read1, Read2);
 
        reg [31:0] i_data;	 
        reg [4:0] temp;
        reg [31:0] register [0:31];                                               //32个寄存器，每个32位，其中$0恒为0
        integer i;
        
    initial begin
        temp = 0;
        for (i = 0 ; i < 32; i = i+1) 
		      register[i] = 0;
		 register[20] = 52;               //为了测试需要的特殊值
    end
    

    always @(RegRead or RegWr) begin
           if (RegRead) begin                                                                                                        
                    if(RegDes)begin                                                                 //i类指令，rt作为写寄存器的目标
                        temp = rt;
                    end
                    else begin
                        temp = rd;
                    end
            Read1 = register[rs];                                               
            Read2 = register[rt]; 
            end    
                      
            if (RegWr) begin   
                    i_data = MemToReg? DataMem:DataALU;            //1则取DataMem的，两个都是数据        
                    if (temp != 0) begin                             //$0寄存器永远保持0
                            register[temp] <= i_data;
                    end
            end
    end
 
endmodule
