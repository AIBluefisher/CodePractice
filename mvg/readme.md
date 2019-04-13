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

## 5. Bundle Adjustment及公式推导

$$
min.\ \sum_{i=1}^m \sum_{j=1}^n ||\bold{x} - \Pi(K, R, \bold{t}, \bold{X})||_2^2
$$

### 5.1 Bundle Adjustment求解

### 5.2 BA中的Jacobian推导

设空间中三维点$P$的坐标为 $\bold{X} = (X, Y, Z)^T$，投影到像素平面的投影点为 $p$，坐标为 $\bold{x} = (x, y)^T$. 相机焦距为$f$，径向畸变参数为 $k_0, k_1$，旋转矩阵（angle-axis）为 $\bold{w} = (w_0, w_1, w_2)^T$，平移向量为 $\bold{t} = (t_0, t_1, t_2)^T$。

投影点对相机参数和三维点的Jacobian可以表示为
$$

$$

由于空间中的三维点投影到二维平面的过程是非线性的，求导过程必然得通过链式法则进行。为此，我们首先需要弄清楚三维点的重投影过程中的整个变换步骤和关系。

#### 1. 相机的投影过程

##### (1) 将三维点从世界坐标系变换到相机坐标系

这一步通过外参计算得到：
$$
\bold{X_c} =  
\left[
    \begin{array}{c}
             x_c \\
             y_c \\
             z_c
    \end{array}
\right] 
= R\bold{X} + \bold{t} 
= R\left[
    \begin{array}{c}
             X \\
             Y \\
             Z
    \end{array}
\right] + \left[
    \begin{array}{c}
             t_0 \\
             t_1 \\
             t_2
    \end{array}
\right] 
$$

这里，我们可以得到相机旋转和平移与相机坐标系三维点之间的运算关系：
$x_c = \bold{R}_0 \bold{X} + t_0$，$y_c = \bold{R}_1 \bold{X} + t_1$，$z_c = \bold{R}_2 \bold{X} + t_2$， 其中，$\bold{R}_i$ 是旋转矩阵 $R$ 的第 $i$ 行。

因为这三个参数都是为关于$R, \bold{X}, \bold{t}$的函数，所以可以更进一步简要表示为 $x_c = T(\bold{R_0}, \bold{X}, t_0), y_c = T(\bold{R_1}, \bold{X}, t_1), z_c = T(\bold{R_2}, \bold{X}, t_2)$

##### (2) 将像极坐标系中的点投影到归一化成像平面

$$
\left[
    \begin{array}{c}
             x \\
             y
    \end{array}
\right] = 
\left[
    \begin{array}{c}
             \frac{x_c}{z_c} \\
             \frac{y_c}{z_c}
    \end{array}
\right] 
$$

##### (3) 对归一化成像平面上的点去畸变并投影至像素平面
这一步可简写为
$$
u = fd(k_0, k_1, r^2)x \\
v = fd(k_0, k_1, r^2)y
$$，其中，$d(k_0, k_1, r^2) = 1 + (k_0 + k_1r^2)r^2$, $r^2 = x^2 + y^2$。

这里我们可以得到 $u, v$ 分别是关于 $f, k_0, k_1x_c, y_c, z_c$ 的函数：
$$
u = \Phi(f, k_0, k_1, x_c, y_c, z_c)\\
v = \Psi(f, k_0, k_1x_c, y_c, z_c)
$$

#### 2. 计算关于焦距的偏导数

求焦距的偏导数比较简单，
$$
\frac{\delta u}{\delta f} = \frac{\delta{\Phi}}{\delta f} = d(k_0, k_1, r^2)x\\
\frac{\delta v}{\delta f} = \frac{\delta{\Psi}}{\delta f} = d(k_0, k_1, r^2)y
$$

#### 3. 计算关于径向畸变参数的偏导数

这里的径向畸变参数有两个，因此，我们需要对这两个参数都求偏导数。很显然，$u$ 和 $v$ 关于 $k_0, k_1$ 的函数都是复合函数，需要用到链式法则求导。

这里我们先把一些之后要求的计算出来，在下面的步骤中要用到时可以直接代入计算：
$$
\frac{\delta u}{\delta d(k_0, k_1, r^2)} = fx\\
\frac{\delta v}{\delta d(k_0, k_1, r^2)} = fy\\
\frac{\delta d(k_0, k_1, r^2)}{\delta k_0} = r^2\\
\frac{\delta d(k_0, k_1, r^2)}{\delta k_1} = r^4
$$

由链式法则，我们有
$$
\frac{\delta u}{\delta k_0} = \frac{\delta u}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta k_0} = fxr^2\\
\frac{\delta u}{\delta k_1} = \frac{\delta u}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta k_1} = fxr^4\\
\frac{\delta v}{\delta k_0} = \frac{\delta v}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta k_0} = fyr^2\\
\frac{\delta v}{\delta k_1} = \frac{\delta v}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta k_1} = fyr^4
$$


#### 4. 计算关于相机外参的偏导数

相机外参包括旋转 $R$ 和平移 $\bold{t}$，我们需要对这两个参数分别求偏导数。同样，我们这里先把一些要求的计算出来，在下面的步骤中直接代入。

$$
\frac{\delta x_c}{\delta t_0} = 1, 
\frac{\delta y_c}{\delta t_1} = 1,
\frac{\delta z_c}{\delta t_2} = 1, \frac{\delta x}{x_c} = 1, \frac{\delta x}{y_c} = 0, \frac{\delta x}{z_c} =- \frac{1}{z_c^2},\\
\frac{\delta u}{\delta x_c} = \frac{\delta u}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta x_c} + \frac{\delta u}{\delta x} \frac{\delta x}{\delta x_c} = \frac{\delta u}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta r^2} \frac{\delta r^2}{\delta x_c} + \frac{\delta u}{\delta x} \frac{\delta x}{\delta x_c} = fx(k_0 + 2k_1r^2)\frac{2x}{z_c} + \frac{1}{z_c} \frac{\delta u}{\delta x}\\
\frac{\delta u}{\delta y_c} = \frac{\delta u}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta y_c} + \frac{\delta u}{\delta x} \frac{\delta x}{\delta y_c} = \frac{\delta u}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta r^2} \frac{\delta r^2}{\delta y_c} + \frac{\delta u}{\delta x} \frac{\delta x}{\delta y_c} = fx(k_0 + 2k_1r^2)\frac{2y}{z_c}\\
\frac{\delta u}{\delta z_c} = \frac{\delta u}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta z_c} + \frac{\delta u}{\delta x} \frac{\delta x}{\delta z_c} = \frac{\delta u}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta r^2} \frac{\delta r^2}{\delta z_c} + \frac{\delta u}{\delta x} \frac{\delta x}{\delta z_c} = -fx(k_0 + 2k_1r^2)\frac{2r^2}{z_c} - \frac{1}{z_c^2} \frac{\delta u}{\delta x}\\
\frac{\delta v}{\delta x_c} = \frac{\delta v}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta x_c} + \frac{\delta u}{\delta x} \frac{\delta x}{\delta x_c} = \frac{\delta v}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta r^2} \frac{\delta r^2}{\delta x_c} + \frac{\delta u}{\delta x} \frac{\delta x}{\delta x_c} = fy(k_0 + 2k_1r^2)\frac{2x}{z_c} + \frac{1}{z_c} \frac{\delta v}{\delta x}\\
\frac{\delta v}{\delta y_c} = \frac{\delta v}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta y_c} + \frac{\delta v}{\delta x} \frac{\delta x}{\delta y_c} = \frac{\delta v}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta r^2} \frac{\delta r^2}{\delta y_c} + \frac{\delta v}{\delta x} \frac{\delta x}{\delta y_c} = fy(k_0 + 2k_1r^2)\frac{2y}{z_c}\\
\frac{\delta v}{\delta z_c} = \frac{\delta u}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta z_c} + \frac{\delta v}{\delta x} \frac{\delta x}{\delta z_c} = \frac{\delta v}{\delta d(k_0, k_1, r^2)} \frac{\delta d(k_0, k_1, r^2)}{\delta r^2} \frac{\delta r^2}{\delta z_c} + \frac{\delta v}{\delta x} \frac{\delta x}{\delta z_c} = -fy(k_0 + 2k_1r^2)\frac{2r^2}{z_c} - \frac{1}{z_c^2} \frac{\delta v}{\delta x}\\
$$

##### 对平移求偏导数
平移向量$\bold{t}$是三维的，需要对 $t_0, t_1, t_2$ 都求偏导数。因为$u$和$v$都是分别关于$x_c, z_c, y_c$的函数，而由第1节的(1)可知，$x_c, y_c, z_c$ 为分别关于 $R$ 和 $\bold{t}_i$ ($i = 0,1,2$) 的函数，所以链式求导过程可以写为：

$$
\frac{\delta u}{\delta t_0} = \frac{\delta u}{\delta x_c} \frac{\delta x_c}{\delta t_0} = \frac{\delta u}{\delta x_c} = fx(k_0 + 2k_1r^2)\frac{2x}{z_c} + \frac{1}{z_c} \frac{\delta u}{\delta x} \\
\frac{\delta u}{\delta t_1} = \frac{\delta u}{\delta y_c} \frac{\delta y_c}{\delta t_1} = \frac{\delta u}{\delta y_c} = fx(k_0 + 2k_1r^2)\frac{2y}{z_c} \\
\frac{\delta u}{\delta t_2} = \frac{\delta u}{\delta z_c} \frac{\delta z_c}{\delta t_2} = \frac{\delta u}{\delta z_c} = -fx(k_0 + 2k_1r^2)\frac{2r^2}{z_c} - \frac{1}{z_c^2} \frac{\delta u}{\delta x}\\
\frac{\delta v}{\delta t_0} = \frac{\delta v}{\delta x_c} \frac{\delta x_c}{\delta t_0} = \frac{\delta v}{\delta x_c} = fy(k_0 + 2k_1r^2)\frac{2x}{z_c} + \frac{1}{z_c} \frac{\delta v}{\delta x} \\
\frac{\delta v}{\delta t_1} = \frac{\delta v}{\delta y_c} \frac{\delta y_c}{\delta t_1} = \frac{\delta v}{\delta y_c} = fy(k_0 + 2k_1r^2)\frac{2y}{z_c} \\
\frac{\delta v}{\delta t_2} = \frac{\delta v}{\delta z_c} \frac{\delta z_c}{\delta t_2} = \frac{\delta v}{\delta z_c} = -fy(k_0 + 2k_1r^2)\frac{2r^2}{z_c} - \frac{1}{z_c^2} \frac{\delta v}{\delta x}
$$

##### 对旋转求偏导数
旋转矩阵维度为 $3\times 3$， 包含 $9$ 个元素。由于旋转矩阵的特殊性 (正交阵，且 $det(R) = 1$)，所以一般不会直接对旋转矩阵的9个元素直接进行优化。通常做法是将旋转矩阵转化为`李代数`(角轴表示法的三维向量)或`四元数`(四维向量)进行优化，再在必要的时候转换回旋转矩阵。这里的旋转矩阵采用轴角表示法的三维向量(相比旋转矩阵的一个明显好处是优化的变量更少了)来计算。

TODO:


#### 5. 计算关于三维点的偏导数

将世界坐标系到相机坐标系的变换写为如下形式：
$$
TODO
$$