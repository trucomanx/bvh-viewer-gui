#PIVMAKE-GUI

##DESCRIPTION

The program implement the PIV technique to the tracking a set of rectangular regions, through of a set of images, the input regions are referenced to the first image.

##INPUT DATA
* A text data file file with the paths of a set of M images to analyze, one path by line. This file by general rule is named with extension *.listfiles.
* A text data file file with set of N images to track, one region by line. This file by general rule is named with extension *.listregions.

###INPUT DATA EXAMPLE: listfilesdata.listfiles
	
	c:\filepath\of\data\image1.bmp
	c:\filepath\of\data\image2.bmp
	c:\filepath\of\data\image3.bmp
	c:\filepath\of\data\image4.bmp
	c:\filepath\of\data\image5.bmp
	c:\filepath\of\data\image6.bmp

The last data file example represent the analysis of M=6 images.
###INPUT DATA EXAMPLE: listregionsdata.listregions

	10  10 32 48
	10  60 32 48
	10 110 32 48

The last data file example represent the analysis of N=3 regions with 32 lines and 48 columns each one. the first region in the position (10,10) the second in the position (10,60) and the third in the position (10,110). The notation is (firstline,firstcolumn).
##OUTPUT DATA
* A set of M text data files with the position of the N regions. These files fulfill the same format of the input regions file.
* A set of M images with the N drawn regions in its corresponding position.

