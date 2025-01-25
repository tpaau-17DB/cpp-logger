# Maintainer: tpaau-17DB tpaau-17db_aur@tutamail.com
pkgname=pretty-logger
pkgver=1.0.0
pkgrel=1
epoch=0
pkgdesc="A C++ logger library."
arch=('x86_64')
url="https://github.com/tpaau-17DB/cpp-logger"
license=('GPL-3.0')
groups=()
depends=('base-devel')
makedepends=()
checkdepends=()
optdepends=()
provides=()
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=("https://github.com/tpaau-17DB/")
noextract=()
md5sums=('')

check() {
    ls /usr/local/include/pretty-logger | grep "Logger.h"
    ls /usr/local/include/pretty-logger | grep "logger.cpp"
}

package() {
    cd "$pkgname-$pkgver"
    sudo ./install
}
