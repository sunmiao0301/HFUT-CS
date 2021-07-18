Img=imread('Lena.jpg'); 
subplot(2,2,1),imshow(Img),title('原始图像');
thresh = graythresh(Img);                 %自动确定二值化阈值
Img_imbinarize = im2bw(Img,thresh);       %对图像二值化
subplot(2,2,2),imshow(Img_imbinarize),title('调用系统函数实现二值化黑白图像');
