
from django.conf.urls import url
from django.urls import path, include

from main import views


urlpatterns = [
	path('', views.index, name='index'),
	path('login', views.login, name='login'),
	path('register', views.register, name='register'),
	path('logout', views.do_logout, name='logout'),
	path('contactus', views.contactus, name='contactus'),
	path('success', views.successView, name='success'),
	path('about/', views.about, name='about'),
]
