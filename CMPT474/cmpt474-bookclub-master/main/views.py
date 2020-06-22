
from django.contrib import auth, messages
from django.contrib.auth import logout
from django.contrib.auth.models import User
from django.core.mail import send_mail, BadHeaderError
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import redirect, render

from .forms import LoginForm, RegisterForm, ContactForm

def index(request):
	return render(request, 'index.html')

def login(request):
	if request.user.is_authenticated:
		return redirect('index')

	if request.method == 'GET':
		return render(request, 'login.html', {'form': LoginForm()})
	else:
		form = LoginForm(request.POST)
		if form.is_valid():
			user = form.user()
			if user:
				auth.login(request, user)
				return redirect('index')
		return render(request, 'login.html', {'form': form})

def register(request):
	if request.user.is_authenticated:
		return redirect('index')

	if request.method == 'GET':
		return render(request, 'register.html', {'form': RegisterForm()})
	else:
		form = RegisterForm(request.POST)
		if form.is_valid():
			user = form.user()
			if user:
				auth.login(request, user)
				return redirect('index')
		return render(request, 'register.html', {'form': form})

def do_logout(request):
	logout(request)
	return redirect('index')

def contactus(request):
    if request.method == 'GET':
        form = ContactForm()
    else:
        form = ContactForm(request.POST)
        if form.is_valid():
            subject = form.cleaned_data['subject']
            from_email = form.cleaned_data['from_email']
            message = form.cleaned_data['message']
            try:
                send_mail(subject, message, from_email, ['admin@example.com'])
            except BadHeaderError:
                return HttpResponse('Invalid header found.')
            return redirect('success')
    return render(request, 'contactus.html', {'form': form})

def successView(request):
    return HttpResponse('Success! Thank you for your message.')

def about(request):
    return render(request, 'about.html', {'title': 'About'})
