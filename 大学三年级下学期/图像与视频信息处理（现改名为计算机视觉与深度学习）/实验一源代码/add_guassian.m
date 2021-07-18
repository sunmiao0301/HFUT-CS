Img=imread('Lena.jpg');
Img_gray = rgb2gray(Img);
subplot(2,2,1),imshow(Img_gray),title('原始图像');
Img_guassian=imnoise(Img_gray ,'gaussian');
subplot(2,2,2),imshow(Img_guassian),title('增加高斯噪声的图像');