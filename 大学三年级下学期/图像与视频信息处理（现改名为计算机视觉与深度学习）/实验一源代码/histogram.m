grayimage=imread('lena_Rgb2Gray_weighting.jpg');
subplot(2,2,1),imshow(grayimage),title('εε§εΎε');
[m,n]=size(grayimage);
gp=zeros(1,256);
for i=1:256    
	gp(i)=length(find(grayimage==(i-1)));
end
subplot(2,2,2),bar(0:255,gp);