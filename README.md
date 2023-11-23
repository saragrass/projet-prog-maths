# projet-prog-maths

## 2. Section de conique
### 2.1 Conique et points de contrôle
D'après un cours sur les coniques, effectuer un changement de repère en faisant une rotation autour de l'origine (point $`O`$) d'un angle spécifique rend l'équation de la conique plus simple : $`ax^2 + cy^2 + dx + ey + f = 0`$, où $`b`$ devient nul. Dans ce cas, choisir 5 points permet d'obtenir 5 équations avec les 5 inconnues précédentes. Il y a ainsi autant d'inconnues que d'équations, on peut donc résoudre.

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

1) L'équation générale d'une conique est : $`ax^2 + bxy + cy^2 + dx + ey + f = 0`$.
L'équation d'une fonction affine (donc ici d'une tangente à la conique) est : $`Ax + B = y`$.
On connait 5 tangentes à la conique, donc il y a 5 équations de ce type connues (A et B sont donnés).
Prenons l'exemple d'une de ces tangentes.
Soit $`M(x,y)`$ le point de tangence entre celle-ci et la conique.
$`M`$ appartient à la tangente et à la conique, donc ses coordonnées vérifient l'égalité : $`Ax - y + B = ax^2 + bxy + cy^2 + dx + ey + f`$. Les données sont $`A`$, $`B`$, $`a`$, $`b`$, $`c`$, $`d`$, $`e`$, $`f`$.
$`Ax - y + B = ax^2 + bxy + cy^2 + dx + ey + f
\Leftrightarrow ax^2 + bxy + cy^2 + (d - A)x + (e + 1)y + (f - B)\times1 = 0
\Leftrightarrow \bigl(\begin{smallmatrix} x^2 & xy & y^2 & x & y & 1 \end{smallmatrix}\bigr) \begin{pmatrix} a\\ b\\ c\\ d - A\\ e + 1\\ f - B\end{pmatrix} = 0`$
qui se généralise sur les points de tangence de chaque tangente à la conique par le système linéaire suivant :
\begin{pmatrix}
x_{1}^{2} & x_{1}y_{1} & y_{1}^{2} & x_{1} & y_{1} & 1 \\ 
x_{2}^{2} & x_{2}y_{2} & y_{2}^{2} & x_{2} & y_{2} & 1 \\
\vdots & \vdots & \vdots & \vdots & \vdots & \vdots \\ 
x_{n}^{2} & x_{n}y_{n} & y_{n}^{2} & x_{n} & y_{n} & 1 \\
\end{pmatrix}
\begin{pmatrix} a\\ b\\ c\\ d - A\\ e + 1\\ f - B \end{pmatrix}
= \begin{pmatrix} 0 \\ 0 \\ \vdots \\ 0 \end{pmatrix}
Il suffit ensuite de calculer ce produit matricielle et de tracer la conique.

Les tangentes à une conique sont perpendiculaires au rayon passant par le centre. Avec cinq tangentes, on obtient cinq points d'intersection sur la conique. En déterminant le centre, les vecteurs du centre aux points d'intersection, perpendiculaires aux tangentes, sont formés. En créant des paires de tangentes, on trouve les points d'intersection correspondants. Ces points définissent la conique en résolvant le système d'équations adéquat.

3) Voir directement dans le code.

4) Une paire de droites est une parabole, spécifiquement lorsque $`b^2 − ac = 0`$ dans l'équation générale $`ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0`$. Cela se simplifie à $`(ax + by + d)(cx + ey + f) = 0`$, représentant deux droites. Pour construire une paire de droites, il suffit ainsi de choisir les coefficients ($`a`$, $`b`$, $`c`$, $`d`$, $`e`$ et $`f`$), écrire l'équation puis la factoriser et s'assurer que l'égalité $`b^2 − ac = 0`$ est bien vérifiée.

5) Quand une conique est un point, elle devient un cercle de rayon nul ($`r = 0`$), simplifiant l'équation du cercle $`(x - h)^2 + (y - k)^2 = r^2`$ à $`(x-h)^2 + (y-k)^2 = 0`$, représentant le point de coordonnées ($`h`$,$`k`$).
