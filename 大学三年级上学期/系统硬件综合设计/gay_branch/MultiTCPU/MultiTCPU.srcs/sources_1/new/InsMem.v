`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/12/08 22:04:06
// Design Name: 
// Module Name: InsMem
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


module InsMem(
        input clk,
        input InsMemRead,
        input [31:0] addr,

        output reg [31:0] ins);
					  
        reg [31:0] out;                                             //一条指令32位（4B）
        reg [7:0] mem [0:127];                             //最多可存放32条指令
	 
	 initial begin
            mem[0]=8'b01100000;mem[1]=8'b00000000;mem[2]=8'b00000000;mem[3]=8'b00000010;
            mem[4]=8'b00000010;mem[5]=8'b10000000;mem[6]=8'b00000000;mem[7]=8'b00010000;
            mem[8]=8'b00000100;mem[9]=8'b00000001;mem[10]=8'b00000000;mem[11]=8'b00001001;
            mem[12]=8'b00010000;mem[13]=8'b00000010;mem[14]=8'b00000000;mem[15]=8'b00000010;
            mem[16]=8'b00010100;mem[17]=8'b00000011;mem[18]=8'b00000000;mem[19]=8'b00000111;
            mem[20]=8'b00100000;mem[21]=8'b00100100;mem[22]=8'b00000000;mem[23]=8'b00000001;
            mem[24]=8'b00000000;mem[25]=8'b01100010;mem[26]=8'b00101000;mem[27]=8'b00000100;
            mem[28]=8'b00000000;mem[29]=8'b10100010;mem[30]=8'b00110000;mem[31]=8'b00000011;
            mem[32]=8'b00000000;mem[33]=8'b11000000;mem[34]=8'b00111000;mem[35]=8'b00000010;
            mem[36]=8'b00000000;mem[37]=8'b00100010;mem[38]=8'b01000000;mem[39]=8'b00001100;
            mem[40]=8'b00000001;mem[41]=8'b00000101;mem[42]=8'b01001000;mem[43]=8'b00000110;
            mem[44]=8'b00000000;mem[45]=8'b00000010;mem[46]=8'b00010000;mem[47]=8'b10001000;
            mem[48]=8'b01000100;mem[49]=8'b01000001;mem[50]=8'b11111111;mem[51]=8'b11110100;
            mem[52]=8'b11000000;mem[53]=8'b01101001;mem[54]=8'b00000000;mem[55]=8'b00000000;
            mem[56]=8'b11000100;mem[57]=8'b00101010;mem[58]=8'b00000000;mem[59]=8'b00000010;
            mem[60]=8'b00000001;mem[61]=8'b01001001;mem[62]=8'b01011000;mem[63]=8'b00000101;
            mem[64]=8'b11111100;mem[65]=8'b00000000;mem[66]=8'b00000000;mem[67]=8'b00000000;

	 end
 
    always @(addr or InsMemRead) begin
          //文件里从左到右是指令地址的从大到小
          if(InsMemRead) begin
                out[31:24] <= mem[addr];
                out[23:16] <= mem[addr+1];
                out[15:8] <= mem[addr+2];
                out[7:0] <= mem[addr+3];                                   //指令不能一次性取完，1B1次取4次，因为1次最多取1字节！
	       end
	 end
	 
	 always @(negedge clk) begin                                   //防止没有读取指令的时候执行
	           if(InsMemRead) ins <= out;                              
	 end
	 
endmodule
