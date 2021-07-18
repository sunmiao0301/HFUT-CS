Img=imread('Lena.jpg'); 
subplot(2,2,1),imshow(Img),title('原始图像');
Img_hsv = rgb2hsv(Img);       %rgb转HSV
 subplot(2,2,2),imshow(Img_hsv),title('hsv图');
