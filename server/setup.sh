#!/bin/sh

BASE_DIR=$(pwd)

echo "Installing..."

echo "#!/bin/sh" > ${BASE_DIR}/run.sh;
echo "" >> ${BASE_DIR}/run.sh;
echo "nohup sh ${BASE_DIR}/get_cpu_usage.sh &" >> ${BASE_DIR}/run.sh 
echo "echo 'The program is running in background'" >> ${BASE_DIR}/run.sh;
chmod +x ${BASE_DIR}/run.sh

echo "Done!"
echo ""
echo "Now you can run ${BASE_DIR}/run.sh"
