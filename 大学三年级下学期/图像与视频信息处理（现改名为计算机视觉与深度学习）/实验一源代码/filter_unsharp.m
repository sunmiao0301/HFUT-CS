Img=imread('Lena.jpg');
Img_gray = rgb2gray(Img);
Img_add_guassian=imnoise(Img_gray ,'gaussian');
f_1=fspecial('unsharp',0.2);%对比度增强滤波器
Img_f1 = imfilter(Img_add_guassian,f_1);
subplot(2,2,1),imshow(Img_f1),title('增加高斯噪声的图像对比度增强滤波处理后');

Img_add_salt=imnoise(Img_gray ,'salt & pepper');
f_1=fspecial('unsharp',0.2);%对比度增强滤波器
Img_f1 = imfilter(Img_add_salt,f_1);
subplot(2,2,2),imshow(Img_f2),title('增加椒盐噪声的对比度增强滤波处理后');
