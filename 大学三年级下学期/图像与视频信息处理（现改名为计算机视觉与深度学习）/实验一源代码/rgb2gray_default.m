Img=imread('Lena.jpg'); 
subplot(2,2,1),imshow(Img),title('原始图像');
[n,m]=size(Img);%判断图像的大小 
GrayImage= rgb2gray(Img);%调用MATLAB函数实现灰度化 
subplot(2,2,2),imshow(GrayImage),title('调用系统函数实现灰度化');
