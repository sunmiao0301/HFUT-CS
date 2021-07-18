Img=imread('Lena.jpg');
Img_gray = rgb2gray(Img);
Img_add_guassian=imnoise(Img_gray ,'gaussian');
Img_f1=medfilt2(Img_add_guassian,[3,3]);%进行3*3中值滤波;
subplot(2,2,1),imshow(Img_f1),title('增加高斯噪声的图像中值滤波处理后');

Img_add_salt=imnoise(Img_gray ,'salt & pepper');
Img_f2=medfilt2(Img_add_salt,[3,3]);%进行3*3中值滤波;
subplot(2,2,2),imshow(Img_f2),title('增加椒盐噪声的中值滤波处理后');
