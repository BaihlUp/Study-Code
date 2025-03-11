基于 Operator 实现大模型私有部署


![](https://raw.githubusercontent.com/BaihlUp/Figurebed/master/2024/202503111047419.png)

1. 因为单实例推理慢，通过 Kong 调用多个实例
2. 通过Operator创建多个实例，并且维持资源池数量
3. 资源池数量变化后，同步更新 Kong 的负载均衡策略