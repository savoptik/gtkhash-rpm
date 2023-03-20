%define _unpackaged_files_terminate_build 1

Name: gtkhash
Version: 1.5
Release: alt2

Summary:GtkHash is a desktop utility for computing message digests or checksums. 

License: GPLv2

Group: Other

Url: https://github.com/tristanheaven/gtkhash

Source0: %name-%version.tar

BuildRequires: libgtk+3-devel
BuildRequires: libglib2-devel
BuildRequires: libgcrypt-devel
BuildRequires: libnettle-devel
BuildRequires: libssl-devel
BuildRequires: libmbedtls-devel
BuildRequires: libb2-devel
BuildRequires: libnautilus-devel
BuildRequires: libnemo-devel
BuildRequires: mate-file-manager-devel
BuildRequires: git
BuildRequires: libkcapi-devel
BuildRequires: libthunar-devel
BuildRequires: librsvg-utils

%description
  GtkHash is a desktop utility for computing message digests or checksums. Most well-known hash functions are supported, including MD5, SHA1, SHA2 (SHA256/SHA512), SHA3 and BLAKE2.
It's designed to be an easy to use, graphical alternative to command-line tools such as md5sum.

%prep
%setup

#git submodule init
#cd gtkhash
#git checkout v1.5

%build
%autoreconf
  %configure \
  --enable-libcrypto       \
  --enable-linux-crypto   \
    --enable-mbedtls        \
    --enable-mhash          \
    --enable-nettle         \
    --enable-caja           \
    --enable-nautilus       \
    --enable-nemo           \
    --enable-thunar         \

%make_build

%install
%makeinstall_std

%check
  %make_build check

%files
%doc AUTHORS ChangeLog NEWS README
%_bindir/*
%_man1dir/%name.1*

%changelog
* Mon Mar 20 2023 Artem Semenov <savoptik@altlinux.org> 1.5-alt2
- 
Initial build for Sisyphus
