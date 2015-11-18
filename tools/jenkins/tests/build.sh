DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
SHREWD_ROOT="$DIR"/../../..	# /.. depends on proj org
cd ${SHREWD_ROOT}
# build here
make -j4	# limit the number of jobs make run simultaneously
if [ ! $? = 0 ]; then
    echo "make generate error"
    exit 1
fi
