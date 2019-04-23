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

![ppl_detection](https://user-images.githubusercontent.com/39265784/56529402-4bfbf480-6516-11e9-918a-e0bd574bf15a.gif)

- Function
1. Draw Squares to detected object and put weights on it.
<img width="469" alt="Screen Shot 2019-04-22 at 3 46 55 PM" src="https://user-images.githubusercontent.com/39265784/56529192-faec0080-6515-11e9-9a8c-59add0feaf86.png">
2. Save detected object by clicking the boxes.
<img width="211" alt="Screen Shot 2019-04-22 at 3 47 26 PM" src="https://user-images.githubusercontent.com/39265784/56529197-fde6f100-6515-11e9-9b7b-138e0da9c21b.png">


-Improvment
: Too low speed to detect objects, even hard to make use 'click & save' fuction. It might be improved by using better computer or Cuda library and use well trained classify function than this given one.

# Acquisitions
1. How to read the open source library code and use it.
2. The way to search in the internet to find what i want.
