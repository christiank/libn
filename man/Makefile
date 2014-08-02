# libn Documentation Makefile
# Christian Koch <cfkoch@sdf.lonestar.org>

.PHONY: default html-docs pdf-docs clean
.SUFFIXES: .html .mdoc .pdf

MANDOC = mandoc

default: html-docs

html-docs: \
	libn.7.html \
	narray.3.html \
	nhash.3.html \
	nstring.3.html

pdf-docs: \
	libn.7.pdf \
	narray.3.pdf \
	nhash.3.pdf \
	nstring.3.pdf

#####

.mdoc.html:
	$(MANDOC) -Thtml $(.ALLSRC) > $(.TARGET)

.mdoc.pdf:
	$(MANDOC) -Tpdf $(.ALLSRC) > $(.TARGET)

#####

clean:
	rm -f *.html *.pdf
