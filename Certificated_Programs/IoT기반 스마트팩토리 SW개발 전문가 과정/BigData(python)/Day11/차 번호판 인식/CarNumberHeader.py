#!/usr/bin/env python
# coding: utf-8

# In[5]:


import numpy as np
import cv2


# In[6]:


def preprocessing(car_no):
    image = cv2.imread('image/%02d.jpg' %car_no, cv2.IMREAD_COLOR)
    if image is None: return None, None
    
    k = np.ones((5, 17), np.uint8)
    g = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    g = cv2.blur(g, (5, 5))
    g = cv2.Sobel(g, cv2.CV_8U, 1, 0, 3)
    
    th_img = cv2.threshold(g, 120, 255, cv2.THRESH_BINARY)[1]
    morph = cv2.morphologyEx(th_img, cv2.MORPH_CLOSE, k, iterations=3)
    
    return image, morph


# In[7]:


def verify_aspect_size(size):
    w , h = size
    if h * w == 0:
        return False
    
    aspect = h/w if h > w else w / h
    chk1 = 3000 < h * w < 1200
    chk2 = 2.0 < aspect < 6.5
    
    return chk1 and chk2


# In[8]:


def find_candidates(image):
    results = cv2.findContours(image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contours = results[0] if len(results) == 2 else results[1]
    rect = [cv2.minAreaRect(c) for c in contours]
    candidates = [(tuple(map(int, center)), tuple(map(int, size)), angle)
                  for center, size, angle in rect if verify_aspect_size(size)]
    
    return candidates


# In[ ]:





# In[ ]:




