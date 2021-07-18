Img=imread('Lena.jpg'); 
subplot(2,2,1),imshow(Img),title('原始图像');
Img_hsv = rgb2hsv(Img);       %rgb转HSV
 [h,s,v] = imsplit(Img_hsv);
 saturationFactor = 2; %S通道乘以比例因子2
 s_temp = s * saturationFactor;
 hsv_temp = cat(3,h,s_temp,v);
 rgb_new = hsv2rgb(hsv_temp);
 subplot(2,2,2),imshow(rgb_new),title('饱和度增强的rgb图');
