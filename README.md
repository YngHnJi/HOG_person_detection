# HOG_person_detection

- HOG Feature
: Histogram of Oriented Gradient
(Using Gradient to classfy object)

- HOW to get HOG Feature
 
1. Calculate Gradients first
  1. In order to find edges, use Mask filter first
  2. Calculate Gradient by the values got from edge detection
![ ](https://user-images.githubusercontent.com/39265784/55844292-35ab6d00-5b02-11e9-8b97-430c63b96570.JPG)  
  3. Quantization gradient values in bins ( 20 degrees * 9 = 180 degrees)
  
2. Make Historams by Cell unit, Make HOG feature by Block unit stitched by histogram cells

