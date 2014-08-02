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

# This is what gets created in the .destdir
INSTALLATION_DIRS=	bin lib

PKG_DESTDIR_SUPPORT=	user-destdir

# We have to supply our own "install" target because mruby's Makefile
# doesn't come with one, nor any equivalents! This also means I'm just
# *making up* what gets installed and what gets left behind.
do-install:
	${INSTALL} ${WRKSRC}/build/host/bin/mirb ${DESTDIR}${PREFIX}/bin/mirb
	${INSTALL} ${WRKSRC}/build/host/bin/mrbc ${DESTDIR}${PREFIX}/bin/mrbc
	${INSTALL} ${WRKSRC}/build/host/bin/mruby ${DESTDIR}${PREFIX}/bin/mruby
	${INSTALL} ${WRKSRC}/build/host/lib/libmruby.a ${DESTDIR}${PREFIX}/lib/libmruby.a
	${INSTALL} ${WRKSRC}/build/host/lib/libmruby_core.a ${DESTDIR}${PREFIX}/lib/libmruby_core.a

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
