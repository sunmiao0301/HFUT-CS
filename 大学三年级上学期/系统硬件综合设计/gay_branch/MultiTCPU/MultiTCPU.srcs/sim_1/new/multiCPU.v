`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/12/12 17:39:02
// Design Name: 
// Module Name: multiCPU
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


module test;
    reg clk;
    reg rst;
    wire[2:0] presentState;
    wire[6:0] a_to_g_0;                   //数码管输出，低16位
    wire[6:0] a_to_g_1;                    //高16位
    wire [31:0] pc;
    wire[7:0] an;
    initial begin
            clk = 1;
            rst = 1;
            #2 rst = 0;
            #130 $stop;
    end
    
    CPU uut(
            .clk(clk),.clk0(clk),.res(rst),.a_to_g_0(a_to_g_0),.a_to_g_1(a_to_g_1),.presentState(presentState),.pcAddr(pc),.an(an)
    );
    
    always  #1clk = ~clk;
endmodule
