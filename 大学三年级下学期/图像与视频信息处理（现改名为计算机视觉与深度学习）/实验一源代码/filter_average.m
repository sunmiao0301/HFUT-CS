Img=imread('Lena.jpg');
Img_gray = rgb2gray(Img);
Img_add_guassian=imnoise(Img_gray ,'gaussian');
f_1=fspecial('average',[3,3]);%3*3均值滤波
Img_f1 = imfilter(Img_add_guassian,f_1);
subplot(2,2,1),imshow(Img_f1),title('增加高斯噪声的图像均值滤波处理后');

Img_add_salt=imnoise(Img_gray ,'salt & pepper');
f_1=fspecial('average',[3,3]);%3*3均值滤波
Img_f1 = imfilter(Img_add_salt,f_1);
subplot(2,2,2),imshow(Img_f1),title('增加椒盐噪声的均值滤波处理后');
