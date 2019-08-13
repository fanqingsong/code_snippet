"use strict";

var page = require('webpage').create();

var fs = require('fs');
page.open('http://localhost/test.html', function () {
    page.evaluate(function(){

    });
});

var ajaxURLCode = {};

page.onConsoleMessage = function(msg, lineNum, sourceId) {
  console.log('CONSOLE: ' + msg + ' (from line #' + lineNum + ' in "' + sourceId + '")');
};

function hereDoc(f) {　
    return f.toString().replace(/^[^\/]+\/\*!?\s?/, '').replace(/\*\/[^\/]+$/, '');
}

page.onLoadFinished = function() {
    console.log("page load finished");

    // 待页面ajax内容加载完毕才 截图 和 保存页面内容
    waitFor(function () {
        return page.evaluate(function () {
            if ( $("#Frm_username").val() != "" ) 
            {
                return true;
            }

            return false;      
        });
    }, function  () {
        // 将每个ajax请求的结果记录到当前page 的DOM 中
        for (var urlPath in ajaxURLCode) {
            console.log("====== urlPath="+urlPath);

            var content = ajaxURLCode[urlPath];

            page.evaluate(function(urlPath, content){
                $("<div style='display:none' id='"+urlPath+"'></div>")
                .text(content)
                .appendTo("body");
            }, urlPath, content);
        };

        // 注入 ajax 请求桩函数， 以实现从页面中缓存显示效果
        page.evaluate(function(hereDoc){
            $("body").prepend("<div id='overwriteAjaxFunc'></div>");

            var ajaxGetRewrite = hereDoc(function () {/*
<script type='text/javascript'>
$(document).ready(function () {
  $.get = function (url, callback) {
     console.log('enter $.get refactor')
     url = url.match('./(.*)')[1];
     var data = $('[id="'+url+'"]').text();
     callback(data);
  }

  $.getJSON = function (url, callback) {
     console.log('enter $.getJSON refactor')
     url = url.match('./(.*)')[1];
     var data = $('[id="'+url+'"]').text();
     data = JSON.parse(data);
     callback(data);
  }  
});
</script>
            */});

            $("#overwriteAjaxFunc").html(ajaxGetRewrite);
        }, hereDoc);


        // 保存页面图片和代码
        page.render('test.png');
        fs.write('test.html', page.content, 'w');
    })
};

page.onResourceRequested = function(requestData, networkRequest) {
    // 判断是否为ajax
    var isAjaxRequested = false;
    var headers = requestData.headers;
    for (var i = 0; i < headers.length; i++) {
        var oneHeader = headers[i];
        var headerName = oneHeader.name;
        var headerValue = oneHeader.value;
        if ( headerName == "X-Requested-With" 
            && headerValue == "XMLHttpRequest" ) 
        {
            isAjaxRequested = true;
        }
    }

    // 只记录AJAX请求的结果
    if ( !isAjaxRequested ) 
    {
        return;
    }

    console.log('Request (#' + requestData.id + '): ' + JSON.stringify(requestData));

    var url = requestData.url;
    console.log(" onResourceRequested url="+url)

    if ( url.match("json$") || url.match("html$") ) 
    {
        var pageRaw = require("webpage").create()
        //pageRaw.settings.javascriptEnabled = false;
        // 借助有jquery的页面 下载 ajax内容
        pageRaw.open('http://localhost/test.html', function  () {
            console.log("url  =----------------- ="+url)
            //console.log("url plainText ="+pageRaw.plainText)
            //console.log("url content ="+pageRaw.content)

            var content = pageRaw.evaluate(function (url) {
                var ajaxRet = "";

                var request = $.ajax({
                    async: false,
                    url: url,
                    dataType: "text"
                });
                 
                request.done(function( msg ) {
                  ajaxRet = msg;
                });

                console.log("ajaxRet="+ajaxRet)
                return ajaxRet;
            }, url)

            console.log("!!!!!!!!!!!!!content="+content);

            // http://xxx/urlpath
            var matchRet = url.match("http://.*/(.*)")
            console.log("matchRet  =----------------- ="+matchRet)
            var urlPath = matchRet[1]
            console.log("urlPath  =----------------- ="+urlPath)

            ajaxURLCode[urlPath] = content;
        })
    }

};

// page.onResourceReceived = function(response) {
//     //console.log('Response (#' + response.id + ', stage "' + response.stage + '"): ' + JSON.stringify(response));

// };


function waitFor(testFx, onReady, timeOutMillis) {
    var maxtimeOutMillis = timeOutMillis ? timeOutMillis : 3000, //< Default Max Timout is 3s
        start = new Date().getTime(),
        condition = false,
        interval = setInterval(function () {
            if ((new Date().getTime() - start < maxtimeOutMillis) && !condition) {
                // If not time-out yet and condition not yet fulfilled
                condition = (typeof (testFx) === "string" ? eval(testFx) : testFx()); //< defensive code
            } else {
                if (!condition) {
                    // If condition still not fulfilled (timeout but condition is 'false')
                    console.log("'waitFor()' timeout");
                    phantom.exit(1);
                } else {
                    // Condition fulfilled (timeout and/or condition is 'true')
                    console.log("'waitFor()' finished in " + (new Date().getTime() - start) + "ms.");
                    typeof (onReady) === "string" ? eval(onReady) : onReady(); //< Do what it's supposed to do once the condition is fulfilled
                    clearInterval(interval); //< Stop this interval
                }
            }
        }, 250); //< repeat check every 250ms
};

