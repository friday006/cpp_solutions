import cv2

def checkOverlap( radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        x = 0 if x1 <= x_center <= x2 else min(abs(x1-x_center), abs(x2-x_center))
        y = 0 if y1 <= y_center <= y2 else min(abs(y1-y_center), abs(y2-y_center))
        return x**2 + y**2 <= radius**2 
  
img = cv2.imread('C:/Users/egpta/Downloads/Channel Window.png')
 
start_point = (0, 0)

end_point = (350, 350)

color = (0, 255, 0)

thickness = 1

cv2.rectangle(img, (410, 210), (200, 400), (0, 255, 0))
center_coordinates = (200, 200)
 
# Radius of circle
radius = 90
  
# Blue color in BGR
color = (255, 0, 0)
  
# Line thickness of 2 px
thickness = 2

image = cv2.circle(img, center_coordinates, radius, color, thickness)

print(checkOverlap(90, 200, 200, 210, 410, 200, 400))

cv2.imshow('image', img)
  
cv2.waitKey(0)
cv2.destroyAllWindows()