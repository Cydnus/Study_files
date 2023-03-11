#!/usr/bin/env python
# coding: utf-8

# In[1]:


from CarNumberHeader import *
import matplotlib.pyplot as plt


# In[2]:


def search():
    car_no = int(input('자동차 영상 번호 (00 ~ 14) : '))
    img, morph = preprocessing(car_no)
    if img is None : Exception("파일 읽기 실패")
    
    candidates = find_candidates(morph)
    for c in candidates:
        pts = np.int32(cv2.boxPoints(c))
        cv2.polylines(img,[pts],True,(0,255,255), 2)
        print(c)
    
    if not candidates:
        print("번호판 후보 영역 미검출")
    plt.figure(figsize=(10, 10))
    plt.imshow(img)
    plt.title(img)
    plt.axis(False)
    plt.show()


# In[ ]:





# In[ ]:





# In[ ]:





# In[3]:


if __name__ == "__main__":
    search()


# In[ ]:




