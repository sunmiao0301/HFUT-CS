`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/12/11 09:49:51
// Design Name: 
// Module Name: extend
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


module Extend(
        input [15:0] in,
        input ExtSel,
		output reg [31:0] out);
  
    always @(in or ExtSel) begin
        if(ExtSel)begin
            out <= {{16{in[15]}}, in[15:0]}; // sign-extend，addi、slti、lw、sw、beq、bne(beq、bne的左移在pc中完成)
         end
         else begin
            out <= {{16{0}}, in[15:0]};                  // zero-extend，ori、andi
         end
    end
 
endmodule
