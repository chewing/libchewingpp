PBXBUILD=xcodebuild
BUILDSTYLE?=Development

all:
	$(PBXBUILD) -buildstyle $(BUILDSTYLE)

clean:
	$(PBXBUILD) clean
	rm -rf build

install:
	$(PBXBUILD) -buildstyle $(BUILDSTYLE) install DSTROOT=/
