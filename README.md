Computing the eigenvalues of a 2x2 matrix
=========================================

Believe it or not, computing the eigen-decomposition of a 2x2 
symmetric matrix is not as trivial as it seems. While I was doing [my M.Eng thesis](http://purl.org/censi/2007/ppu),  at a certain point I was implementing two algorithms:

- the `eig_symm_*` algorithm of the [GNU Scientific Library][gsl].
- the closed-form algorithm described in:

  > [Jim Blinn], "*[Consider the Lowly 2x2 Matrix][consider]*", IEEE Computer Graphics and Applications, March 1996, pp. 82-88.

And I found bugs in both!  GSL would fail on simple cases: for diagonal matrices it would return two equal eigen-vectors. Blinn's algorithm has a couple of minor bugs.

The source code presented here contains Blinn's algorithm with a couple of corrections.

[Jim Blinn]: http://research.microsoft.com/users/blinn/
[gsl]: http://www.gnu.org/software/gsl/
[consider]: http://dx.doi.org/10.1109/38.486688
