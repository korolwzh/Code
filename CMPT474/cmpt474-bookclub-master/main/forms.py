
from django import forms
from django.contrib import auth
from django.contrib.auth.models import User

class LoginForm(forms.Form):
	username = forms.CharField()
	password = forms.CharField(widget=forms.PasswordInput())

	def clean(self):
		user = self.user()
		if not user or not user.is_active:
			raise forms.ValidationError('Invalid username or password')
		return self.cleaned_data

	def user(self):
		return auth.authenticate(
			username=self.cleaned_data.get('username'),
			password=self.cleaned_data.get('password')
		)

	class Meta:
		model = User

class RegisterForm(forms.Form):
	username = forms.CharField()
	password = forms.CharField(widget=forms.PasswordInput())
	password_confirmation = forms.CharField(widget=forms.PasswordInput())

	def clean(self):
		try:
			user = User.objects.get(username=self.cleaned_data.get('username'))
		except User.DoesNotExist:
			pass
		else:
			raise forms.ValidationError('User already exists')
		if self.cleaned_data.get('password') != self.cleaned_data.get('password_confirmation'):
			raise forms.ValidationError('Passwords do not match')
		return self.cleaned_data

	def user(self):
		return User.objects.create_user(
			username=self.cleaned_data.get('username'),
			password=self.cleaned_data.get('password')
		)

	class Meta:
		model = User

class ContactForm(forms.Form):
	from_email = forms.EmailField(required=True)
	from_email.widget.attrs.update({"type":"email", "id":"input_7", "name":"q7_email", "class":"form-textbox validate[required, Email]", "size":"25", "value":"", "placeholder":" ", "data-component":"email", "aria-labelledby":"label_7", "required":""})
	subject = forms.CharField(max_length=100, required=True)
	subject.widget.attrs.update({"type":"text", "id":"input_8", "name":"q8_fullName", "data-type":"input-textbox", "class":"form-textbox validate[required]", "size":"25", "value":"", "placeholder":" ", "data-component":"textbox", "aria-labelledby":"label_8", "required":"" })
	message = forms.CharField(widget=forms.Textarea, required=True)
	message.widget.attrs.update({"id":"input_4", "class":"form-textarea validate[required]", "name":"q4_message4", "cols":"28", "rows":"6", "data-component":"textarea", "required":"", "aria-labelledby":"label_4"})
