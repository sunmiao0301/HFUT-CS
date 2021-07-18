Img=imread('Lena.jpg');
Img_gray = rgb2gray(Img);
Img_add_guassian=imnoise(Img_gray ,'gaussian');
f1= fspecial('gaussian',[3,3],1);
Img_f1 = imfilter(Img_add_guassian,f1,'replicate');
% J2= fspecial('gaussian',[9,9],1); 
% I2 = imfilter(I,J2,'replicate');
subplot(2,2,1),imshow(Img_f1),title('增加高斯噪声的图像高斯滤波处理后');

Img_add_salt=imnoise(Img_gray ,'salt & pepper');
Img_f2 = imfilter(Img_add_salt,f1,'replicate');
subplot(2,2,2),imshow(Img_f2),title('增加椒盐噪声的高斯滤波处理后');
