#!/usr/bin/tcsh -f

#rm article.dvi.ps article.dvi.pdf article.dvi article.log article.aux


#latex article.tex
#latex article.tex
#dvips -oarticle.dvi.ps article.dvi
#ps2pdf article.dvi.ps
#acroread article.dvi.pdf


#!/bin/tcsh -f
rm article.pdf
rm article.aux
rm article.bbl


rm text/aliases/*.aux text/setups/*.aux text/toc/*.aux text/*/*.aux

pdflatex article
bibtex article
pdflatex article
pdflatex article
acroread article.pdf >& /dev/null
rm article.log article.aux article.toc article.out article.blg article.bbl
