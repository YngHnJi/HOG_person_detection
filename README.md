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

- SVM (Support Vector Machine)
: Binary Classifier

1. Find two groups divided well each other, and get the point for the center of each group
2. Based on center point for each two groups, set the Hyper Plane, which is the line distinguish two types
(Convex Hall is a kinds of contour grouping same types, and Support Vector is the cloest vector from Hyper Plane
3. For more accurate classifying, put datas in 2 or 3 dimemsion is called 'Kernel Trick'

=> Extracting Feature Values by Hog Feature and Classifying object/Not object by SVM

- HOG Person Detector
: Classifying person or Not Person by HOG feature trained by Support Vector Machine

- How detect person
![IMG_2395](https://user-images.githubusercontent.com/39265784/55845193-86bd6000-5b06-11e9-9c08-0f194560730f.JPG)



- Video

- Function
