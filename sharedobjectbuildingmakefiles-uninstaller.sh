echo Uninstallation started!

rm -rf --verbose $SHARED_OBJECT_BUILDING_MAKEFILES_BASE_DIR
sudo rm -f --verbose $SOBM_LD_CONFIG_FILE
sudo ldconfig

echo Uninstallation was successful!
