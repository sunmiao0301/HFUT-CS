Img=imread('Lena.jpg');
Img_gray = rgb2gray(Img);
subplot(2,2,1),imshow(Img_gray),title('原始图像');
Img_salt=imnoise(Img_gray ,'salt & pepper');
subplot(2,2,2),imshow(Img_salt),title('增加椒盐噪声的图像');