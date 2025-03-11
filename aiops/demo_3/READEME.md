1. 通过 Operator 获取 Loki 中的错误日志
2. Operator 调用 LLM 对错误日志进行分析，返回是否需要发送 Feishu 告警的标识
3. 如果需要发送 Feishu，则调用 Feishu Webhook

![image.png](https://raw.githubusercontent.com/BaihlUp/Figurebed/master/2024/20250311141344.png)

创建 Operator 项目：
```bash
go mod init github.com/baihlUp/llm-log-operator
kubebuilder init --domain=aiops.com
kubebuilder create api --group log --version v1 --kind LogPilot
```