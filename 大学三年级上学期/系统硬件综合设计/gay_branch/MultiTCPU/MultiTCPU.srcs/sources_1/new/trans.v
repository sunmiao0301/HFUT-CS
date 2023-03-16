`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/12/25 18:54:03
// Design Name: 
// Module Name: trans
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


module trans(                                       //将32位二进制数转为数码管显示
        input [15:0] x,             //对应4个数码管的数据
        input clk,                  //时钟
        input rst,
        output reg [6:0] a_to_g,    //数码管段选信号
	    output reg [3:0] an         //数码管位选信号，4位为1组
);
        reg [3:0] digit;
        reg [19:0] clkdiv;          //计数器,分频用:每次改变选择一个数码管进行输出显示
        
	   always @(*)begin                //将输入的值分配给digit，每隔clkdiv[19:18]的时间分配一次
                case(clkdiv[19:18])     //每5.2ms将计数器改变一次
                    0: digit = x[3:0];
                    1: digit = x[7:4];
                    2: digit = x[11:8];
                    3: digit = x[15:12];
                default: digit = x[3:0];
	           endcase
        end
        
        always @(*)begin
                case(digit)     //判断开关输入的值，控制a~g,显示不同的字符                                 
                        0:a_to_g=7'b1111110;
                        1:a_to_g=7'b0110000;
                        2:a_to_g=7'b1101101;
                        3:a_to_g=7'b1111001;
                        4:a_to_g=7'b0110011;
                        5:a_to_g=7'b1011011;
                        6:a_to_g=7'b1011111;
                        7:a_to_g=7'b1110000;
                        8:a_to_g=7'b1111111;
                        9:a_to_g=7'b1111011;
                        'hA:a_to_g=7'b1110111;
                        'hB:a_to_g=7'b0011111;
                        'hC:a_to_g=7'b1001110;
                        'hD:a_to_g=7'b0111101;
                        'hE:a_to_g=7'b1001111;
                        'hF:a_to_g=7'b1000111;
                        default: a_to_g=7'b1111110;
                endcase
            end
            
        always @( * )begin      //每隔clkdiv[19:18]段时间点亮一个数码管
                an = 4'b0000;
	            an[clkdiv[19:18]] = 1;
        end

    always @( posedge clk or posedge rst)begin    //对clkdiv进行累加，以便分频
            if( rst == 1 )
    	           clkdiv <= 0;
	       else
                   clkdiv <= clkdiv + 1;
    end
    
endmodule
