module.exports = {
  'Find the answer.': function(client) {
    // 启动浏览器并打开 bing.com.
    client.url('http://www.txrjy.com');

    // 确保 "body" 和输入框可以使用.
    client.expect.element('body').to.be.present;
    client.end();
  },
};