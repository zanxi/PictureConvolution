# PictureConvolution
свертка матрицы изображения в градациях серого (байт на элемент) с матрицей A(ядро свертки convolution)

// TODO: Add your command handler code here
	float kernel[5][5] = {
			1,	4,	6,	4,	1,
			4,	16,	24,	16,	4,
			6,	24,	36,	24,	6,
			4,	16,	24,	16,	4,
			1,	4,	6,	4,	1
	};
	((CImageConvolutionView*)GetActiveView())->ConvolveImage(kernel,0);
  
  функция свертки - шейдера
  
COLORREF CImageConvolutionView::Convolve(CDC* pDC, int sourcex, int sourcey, float kernel[5][5], int nBias,BOOL bGrayscale)
{
	float rSum = 0, gSum = 0, bSum = 0, kSum = 0;
	COLORREF clrReturn = RGB(0,0,0);
	for (int i=0; i <= 4; i++)//loop through rows
	{
		for (int j=0; j <= 4; j++)//loop through columns
		{
			//get pixel near source pixel
			/*
			if x,y is source pixel then we loop through and get pixels at coordinates:
			x-1,y-1
			x-1,y
			x-1,y+1
			x,y-1
			x,y
			x,y+1
			x+1,y-1
			x+1,y
			x+1,y+1
			*/
			COLORREF tmpPixel = pDC->GetPixel(sourcex+(i-(2>>1)),sourcey+(j-(2>>1)));
			//get kernel value
			float fKernel = kernel[i][j];
			//multiply each channel by kernel value, and add to sum
			//notice how each channel is treated separately
			rSum += (GetRValue(tmpPixel)*fKernel);
			gSum += (GetGValue(tmpPixel)*fKernel);
			bSum += (GetBValue(tmpPixel)*fKernel);
			//add the kernel value to the kernel sum
			kSum += fKernel;
		}
	}
	//if kernel sum is less than 0, reset to 1 to avoid divide by zero
	if (kSum <= 0)
		kSum = 1;
	//divide each channel by kernel sum
	rSum/=kSum;
	gSum/=kSum;
	bSum/=kSum;
	//add bias if desired
	rSum += nBias;
	gSum += nBias;
	bSum += nBias;
	//prevent channel overflow by clamping to 0..255
	if (rSum > 255)
		rSum = 255;
	else if (rSum < 0)
		rSum = 0;
	if (gSum > 255)
		gSum = 255;
	else if (gSum < 0)
		gSum = 0;
	if (bSum > 255)
		bSum = 255;
	else if (bSum < 0)
		bSum = 0;
	//return new pixel value
	if (bGrayscale)
	{
		int grayscale=0.299*rSum + 0.587*gSum + 0.114*bSum;
		rSum=grayscale;
		gSum=grayscale;
		bSum=grayscale;
	}

	clrReturn = RGB(rSum,gSum,bSum);
	return clrReturn;
}
  
  
