/*global WildRydes _config*/

var WildRydes = window.WildRydes || {};
WildRydes.map = WildRydes.map || {};

(function rideScopeWrapper($) {
    var authToken;
    WildRydes.authToken.then(function setAuthToken(token) {
        if (token) {
            authToken = token;
        } else {
            window.location.href = '/signin.html';
        }
    }).catch(function handleTokenError(error) {
        alert(error);
        window.location.href = '/signin.html';
    });
    function request(title, content) {
        $.ajax({
            method: 'POST',
            url: _config.api.invokeUrl + '/create',
            headers: {
                Authorization: authToken
            },
            data: JSON.stringify({
                Post: {
                    Title: title,
                    Content: content,
                }
            }),
            contentType: 'application/json',
        });
        setTimeout(alert("Created successfully."), 3000);
        window.location.reload();
    }

    // Register click handler for #request button
    $(function onDocReady() {
        $('#createPostForm').submit(handleRequestSubmit);
        $('#signOut').click(function() {
            WildRydes.signOut();
            alert("You have been signed out.");
            window.location = "signin.html";
        });

        if (!_config.api.invokeUrl) {
            $('#noApiMessage').show();
        }
    });

    function handleRequestSubmit(event) {
        var title = $('#title').val();
        var content = $('#content').val();
        event.preventDefault();
        request(title, content);
    }


}(jQuery));
