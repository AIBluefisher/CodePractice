## 0. 多视图几何中涉及到的线性代数

### 0.0 奇异值分解 (Singular Value Decomposition, SVD)

### 0.1 齐次方程组的最小二乘解
求形如$A\bold{x} = 0$的方程组的解。我们寻求该方程组的非零解。注意，如果$\bold{x}$是这个方程组的解，那么 $k\bold{x}$ 也是这个方程组的解。因此，一个合理的约束是只求$||x|| = 1$的解。
令 $A = UDV^T$，则我们需最小化$||A\bold{x}|| = ||UDV^T\bold{x}||$。
由于正交矩阵的保范性，有 $||UDV^T\bold{x}|| = ||U^TUDV^T\bold{x}|| = ||DV^T\bold{x}||$。
令 $\bold{y} = V^T\bold{x}$, 则我们最小化 $||D\bold{y}||$。因为$D$是按特征值降序排列的对角阵，很容易能推出最小化 $||D\bold{y}||$ 的解为 $\bold{y} = (0, 0, 0, ..., 1)^T$。而 $\bold{x} = V\bold{y}$，所以 $\bold{x}$ 就是 $V$ 的最后一列。

## 1. 对极几何 (epipolar geometry)

### 1.1 对极几何的推导
假设两个相机 $C_1$ 和 $C_2$ 所拍摄的图片分别为 $A$ 和 $B$，$\bold{x}$ 和 $\bold{x^{'}}$ 为其中一对`匹配点(correspondence)`，$X$为这对匹配点在空间中所对应的三维坐标点，$C_1$ 与 $C_2$的连线与两幅图像平面的交点分别为 $\bold{e}$ 和 $\bold{e^{'}}$ (即`对极点`)。两幅图像平面上的`对极线`分别为 $\bold{l}$ 和 $\bold{l^{'}}$。

#### 1. 几何方法
对于第二幅图像上的对极线$\bold{l^{'}}$，我们可以通过$\bold{x^{'}}$和$\bold{l^{'}}$的叉乘计算得到，即
$$
\bold{l^{'}} = \bold{e^{'}} \times \bold{x^{'}} = [\bold{e^{'}}]_{\times} \bold{x^{'}}
$$
对于第二幅图像上的点$\bold{x^{'}}$，总能通过一个单应的变换关系，将第一幅图像上所对应的点\bold{x}变换到$\bold{x^{'}}$，即
$$
\bold{x^{'}} = H\bold{x}
$$
于是，我们有

$$
\bold{l^{'}} = [\bold{e^{'}}]_{\times} \bold{x^{'}} = [\bold{e^{'}}]_{\times}H\bold{x}
$$
因为点$\bold{x^{'}}$位于对极线$\bold{l^{'}}$上，于是有
$$
\bold{x^{'}}^T\bold{l^{'}} = \bold{x^{'}}^T [\bold{e^{'}}]_{\times}H\bold{x} = 0
$$

其中，$F = [\bold{e^{'}}]_{\times}H$，则
$$
\bold{x^{'}}^T F \bold{x} = 0
$$
$F$ 就是我们常说的`基本矩阵(fundamental matrix)`。


#### 2. 代数方法

## 1. Homography计算及实现
对于齐次坐标下的二维表示，homography为$3\times 3$的矩阵，其中最后一个元素为尺度因子(`scale factor`)，因此一个单应具有8个自由度(Degree of Freedom, DoF)。令 $\bold{x}=(x, y, 1)^T$, $\bold{x^{'}}=(x^{'}, y^{'}, 1)^T$，单应矩阵$H$按行优先排列为$(h_{11}, h_{12}, h_{13}, h_{21}, h_{22}, h_{23}, h_{31}, h_{32}, h_{33})$，令 $\bold{h} = (h_1, h_2, h_3, h_4, h_5, h_6, h_7, h_8, h_9)^T$。

计算单应矩阵的公式为:
$$
\bold{x^{'}} = H\bold{x}
$$
转换为叉乘表示为：
$$
\bold{x^{'}} \times H\bold{x} = 0
$$

TODO: 中间推导

最终，方程可以转换成 $A \bold{h} = 0$ 的形式。对于这样一个其次方程组，我们可以用 0.1节求解`齐次方程组的最小二乘解`的方法来求解，$h$也就是$A$的SVD分解中矩阵 $V$ 的最后一列。

## 2. Fundamental matrix计算及实现

### 2.1 七点法

### 2.2 八点法

## 3. Essential Matrix计算及实现

## 4. RANSAC实现