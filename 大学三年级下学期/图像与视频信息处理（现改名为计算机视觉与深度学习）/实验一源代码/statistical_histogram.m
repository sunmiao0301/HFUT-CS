grayimage=imread('lena_Rgb2Gray_weighting.jpg');
subplot(2,2,1),imshow(grayimage),title('原始图像');
[m,n]=size(grayimage);
gp=zeros(1,256);
for i=1:256    
	gp(i)=length(find(grayimage==(i-1)))/(m*n);%(m*n)使之成为统计直方图
end
subplot(2,2,2),bar(0:255,gp);