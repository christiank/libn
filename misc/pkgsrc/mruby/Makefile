# $NetBSD$
#

DISTNAME=	mruby-1.0.0
PKGNAME=	mruby-1.0.0
CATEGORIES=	local
MASTER_SITES=	http://lipgloss.local/~christian/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	cfkoch@sdf.lonestar.org
HOMEPAGE=	http://www.mruby.org
COMMENT=	Lightweight implementation of Ruby
LICENSE=	mit

BUILD_DEPENDS+=	ruby>=0.0.0:../../lang/ruby

INSTALLATION_DIRS=	bin lib include include/mruby

INCLUDE_FILES =	\
	mrbconf.h \
	mruby.h \
	mruby/array.h \
	mruby/class.h \
	mruby/compile.h \
	mruby/data.h \
	mruby/debug.h \
	mruby/dump.h \
	mruby/gc.h \
	mruby/hash.h \
	mruby/irep.h \
	mruby/khash.h \
	mruby/numeric.h \
	mruby/proc.h \
	mruby/range.h \
	mruby/string.h \
	mruby/value.h \
	mruby/variable.h

BIN_FILES =	mirb mrbc mruby
LIB_FILES =	libmruby.a libmruby_core.a

# We have to supply our own "install" target because mruby's Makefile
# doesn't come with one, nor any equivalents! This also means I'm just
# *making up* what gets installed and what gets left behind.
do-install:
	@for b in ${BIN_FILES}; do \
		${INSTALL} ${WRKSRC}/build/host/bin/$${b} ${DESTDIR}${PREFIX}/bin/$${b}; \
	done
	@for l in ${LIB_FILES}; do \
		${INSTALL} ${WRKSRC}/build/host/lib/$${l} 	${DESTDIR}${PREFIX}/lib/$${l}; \
	done
	@for h in ${INCLUDE_FILES}; do \
		cp -v ${WRKSRC}/include/$${h} ${DESTDIR}${PREFIX}/include/$${h}; \
	done

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
