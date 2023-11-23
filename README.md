# projet-prog-maths

## 2. Section de conique
### 2.1 Conique et points de contrôle
Comme nous sommes en géométrie projective, les points peuvent être définis à un facteur près. Cela permet "d'éliminer" une composante (ici le $`w`$ qui vaudra alors $`1`$ ne sera plus une inconnue) et on se retrouve donc avec 5 inconnues pour 5 équations : $`ax^2 + cy^2 + dx + ey + f = 0`$.

### 2.4 Coniques
On a :
$`x^T \times C \times x = 0`$
<br>$`\Leftrightarrow x^T \times C^T \times x = 0`$ (comme $`C`$ est symétrique, alors elle vérifie la propriété suivante : $`C = C^T`$)
<br>$`\Leftrightarrow (C \times x)^T \times x = 0`$ (car $`x^T × C^T = (C \times x)^T`$)
<br>$`\Leftrightarrow (C \times x)^T \times Id \times x = 0`$ (car la matrice $`Id`$ est un élément neutre pour la multiplication)
<br>$`\Leftrightarrow (C \times x)^T \times C^{-1} \times C \times x = 0`$ (en remplaçant $`Id`$ par $`C^{-1} \times C`$)
<br>$`\Leftrightarrow l^T \times C^{-1} \times l = 0`$ (en posant : $`l = C \times x`$)

## 3. À réaliser

### 3.1 Mathématiques avancées

1) D'après le <b>2.4 Coniques</b>, une droite $`l`$ est tangente à la conique $`C`$ ssi : $`l^TC^{-1}l = 0`$. Cette tangente passe par le point $`x \in C`$ : $`l = Cx`$ (avec $`x = (x, y)^T`$).

On connait 5 tangentes à la conique, donc il y a 5 équations de ce type dont on connait les $`l_i`$ (avec $`i\in[1,5]`$) et il y a 5 points de contrôle connus (ici ce sont points de contact entre les différentes tangentes et la conique). Une conique peut être définie par un ensemble de 5 points de contrôle $`\left \{ x_i \right \}_{i \in 1...5}`$ satisfaisant l'équation : $`\begin{pmatrix}
x_{1}^{2} & x_{1}y_{1} & y_{1}^{2} & x_{1} & y_{1} & 1 \\ 
x_{2}^{2} & x_{2}y_{2} & y_{2}^{2} & x_{2} & y_{2} & 1 \\
\vdots & \vdots & \vdots & \vdots & \vdots & \vdots \\ 
x_{n}^{2} & x_{n}y_{n} & y_{n}^{2} & x_{n} & y_{n} & 1 \\
\end{pmatrix}
\begin{pmatrix} a\\ b\\ c\\ d \\ e \\ f \end{pmatrix}
= \begin{pmatrix} 0 \\ 0 \\ \vdots \\ 0 \end{pmatrix}`$.

De plus, comme on sait que les droites $`l_i`$ sont tangentes à la conique, elles vérifient : $`l_{i}^{T}C^{-1}l_{i} = 0`$. On remplace ensuite les $`l_{i}`$ par $`Cx_{i}`$. On a : $`(Cx_{i})^T \times C^{-1} \times Cx_{i} = 0`$.

On a donc un système linéaire à 5 équations (une par tangente). On le résout avec la méthode des moindres carrés et on trouve les coefficients $`a`$, $`b`$, $`c`$, $`d`$, $`e`$ et $`f`$ permettant de tracer la conique : $`C = \begin{bmatrix} a & b/2 & d/2 \\ b/2 & c & e/2 \\ d/2 & e/2 & f \end{bmatrix}`$.

2) Voir directement dans le code.

3) Une conique sous forme de paires de droites dans le plan projectif peut être représentée par une équation matricielle particulière. La forme standard d'une conique dans la géométrie projective : $`x^TCx = 0`$ où $`x = (x,y,w)^T`$ est un point homogène, et $`C`$ est la matrice de la conique.
Cependant, pour une conique qui est une paire de droites, la matrice $`C`$ prend une forme spécifique. En particulier, elle peut être décomposée en deux matrices $`C_1`$ et $`C_2`$, chacune représentant une droite : $`C = C_1 + C_2`$.
Une équation équivalente serait : $`x^{T}C_1x \cdot x^{T}C_2`$.
Cela signifie que la conique peut être vue comme l'intersection de deux droites, où $`C_1x = 0`$ et $`C_2x = 0`$.

La construction de cette conique à partir de cinq points peut être réalisée en suivant une procédure similaire à la construction d'une conique ordinaire, mais avec la particularité que les cinq points choisis définissent deux droites plutôt qu'une seule. La matrice $`C`$ résultante est une combinaison linéaire des matrices $`C_1`$ et $`C_2`$ associées à ces deux droites.

4) Quand une conique est un point, elle devient un cercle de rayon nul ($`r = 0`$), simplifiant l'équation du cercle $`(x - h)^2 + (y - k)^2 = r^2`$ à $`(x-h)^2 + (y-k)^2 = 0`$, représentant le point de coordonnées ($`h`$,$`k`$).
