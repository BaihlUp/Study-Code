import http.client
import json
def sendEmail(to_email, email_content):
    conn = http.client.HTTPSConnection("chat.jijyun.cn")
    payload = json.dumps({
       "instructions": f"帮我给{to_email}发送一个邮件，邮件内容是：{email_content}。",
       "preview_only": False
    })
    headers = {
       'User-Agent': 'Apifox/1.0.0 (https://apifox.com)',
       'Content-Type': 'application/json'
    }
    conn.request("POST", "/v1/openapi/exposed/224517_1524_jjyibotID_152b60c9777149c19b1edbc2fced80e3/execute/?apiKey=aZfvz8kV3WsOjmbrrl1428ut1730368527", payload, headers)
    res = conn.getresponse()
    data = res.read()
    print(data.decode("utf-8"))

if __name__ == '__main__':
    to_email = "1260475686@qq.com"
    sendEmail(to_email, "你好，测试邮件")