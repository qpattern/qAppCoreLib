# This snippet iterates through all variables inside qmake during processing of the
# given .pro file (enumerate_vars).
# That list is filtered ignoring these patterns: "QMAKE_*", "QT.*", "QT_*", ".QMAKE*".
# The variable is named QT_varfile to avoid it appearing in the generated list.
# The generated metadata file ("qmake.vars") can then be read by Gradle, or other build tools

isEmpty(QT_VAR_OUD_DIR) {
    message("cazzo")
    QT_VAR_OUD_DIR=$$OUT_PWD
}

QT_varfile = ""
for(var, $$list($$find($$list($$enumerate_vars()), ^(?!QMAKE_.*|QT\..*|QT_.*|\.QMAKE.*).*$))) {
    line = $$var "$$eval($$var)"
    QT_varfile += $$join(line, "=")
}
write_file($$absolute_path("qmake.vars", $$QT_VAR_OUD_DIR), QT_varfile)

android {
    # Copy the needed gradle scripts to the build folder
    copyGradleScripts.commands = $(MKDIR) $$QT_VAR_OUD_DIR/android-build/; $(COPY_DIR) $$PWD/platform/android/*.gradle $$QT_VAR_OUD_DIR/android-build/
    first.depends += $(first) copyGradleScripts
    QMAKE_EXTRA_TARGETS += first copyGradleScripts
}
