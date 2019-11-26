package com.emulamer.installerhelper;

import com.google.common.collect.ImmutableList;

import org.jf.dexlib2.DexFileFactory;
import org.jf.dexlib2.Opcode;
import org.jf.dexlib2.dexbacked.instruction.*;
import org.jf.dexlib2.dexbacked.reference.*;
import org.jf.dexlib2.iface.*;
import org.jf.dexlib2.dexbacked.DexBackedClassDef;
import org.jf.dexlib2.dexbacked.DexBackedDexFile;
import org.jf.dexlib2.dexbacked.DexBackedMethod;
import org.jf.dexlib2.iface.instruction.Instruction;
import org.jf.dexlib2.iface.reference.Reference;
import org.jf.dexlib2.rewriter.DexRewriter;
import org.jf.dexlib2.rewriter.RewriterModule;
import org.jf.dexlib2.rewriter.*;

import javax.annotation.Nonnull;
import javax.annotation.Nullable;
import java.io.File;




public class DexHelper {

    public boolean checkDexInjection(File classesDexFilename) throws Exception {
        DexBackedDexFile dexFile = DexFileFactory.loadDexFile(classesDexFilename, null);
        return checkDexInjected(dexFile);
    }

    public boolean checkDexInjectionGeneric(File classesDexFilename, @Nullable String targetClass) throws Exception {
        DexBackedDexFile dexFile = DexFileFactory.loadDexFile(classesDexFilename, null);
        if (targetClass == null) {
            targetClass = findInjectClass(dexFile);
        }
        if (targetClass == null)
            throw new Exception("Could not find target class");
        return checkDexInjectedGeneric(dexFile, targetClass);
    }

    private String opName(Opcode code) {
        return "Opcode." + code.name();
    }

    public String writeJavaBytecodeWritingJavaCode(DexBackedDexFile dexFile) {
        String output = "";
        for (DexBackedClassDef dexClass : dexFile.getClasses()) {
            String type = dexClass.getType();

            int methodCtr = 0;
            for (DexBackedMethod m : dexClass.getMethods()) {

                String paramsDef = "";
                int paramCtr = 0;
                for (MethodParameter mp : m.getParameters()) {
                    if (paramCtr > 0) {
                        paramsDef = paramsDef + ", ";
                    }

                    String paramName = mp.getName();
                    if (paramName == null)
                        paramName = "null";
                    else
                        paramName = "\"" + paramName + "\"";
                    String newMP = "new ImmutableMethodParameter(\"" + mp.getType() + "\",null," + paramName + ")";
                    paramsDef = paramsDef + newMP;
                    paramCtr++;
                }
                if (paramCtr == 0)
                    paramsDef = "List<ImmutableMethodParameter> parameters" + methodCtr + " = null;";
                else
                    paramsDef = "List<ImmutableMethodParameter> parameters" + methodCtr + " = Arrays.asList(" + paramsDef + ");";
                MethodImplementation impl = m.getImplementation();

                String instructions = "";
                int instrCtr = 0;
                for (Instruction inst : impl.getInstructions()) {
                    if (instrCtr > 0)
                        instructions += ", ";

                    String instStr = "";
                    Opcode opcode = inst.getOpcode();
                    String className = inst.getClass().getName();
                    if (inst instanceof DexBackedInstruction21c) {
                        DexBackedInstruction21c typ = (DexBackedInstruction21c) inst;
                        instStr = "new ImmutableInstruction21c(" + opName(inst.getOpcode()) + ", " + typ.getRegisterA() + ", " + doRef(typ.getReference()) + ")";
                    } else if (inst instanceof DexBackedInstruction35c) {
                        DexBackedInstruction35c typ = (DexBackedInstruction35c) inst;
                        instStr = "new ImmutableInstruction35c(" + opName(inst.getOpcode()) + ", " + typ.getRegisterCount() + "," + typ.getRegisterC() + ", " + typ.getRegisterD() + ", " + typ.getRegisterE() + ", " + typ.getRegisterF() + ", " + typ.getRegisterG() + ", " + doRef(typ.getReference()) + ")";
                    } else if (inst instanceof DexBackedInstruction10x) {
                        DexBackedInstruction10x typ = (DexBackedInstruction10x) inst;
                        instStr = "new ImmutableInstruction10x(" + opName(inst.getOpcode()) + ")";
                    } else if (inst instanceof DexBackedInstruction22c) {
                        DexBackedInstruction22c typ = (DexBackedInstruction22c) inst;
                        instStr = "new ImmutableInstruction22c(" + opName(inst.getOpcode()) + ", " + typ.getRegisterA() + ", " + typ.getRegisterB() + ", " + doRef(typ.getReference()) + ")";
                    } else if (inst instanceof DexBackedInstruction11x) {
                        DexBackedInstruction11x typ = (DexBackedInstruction11x) inst;
                        instStr = "new ImmutableInstruction11x(" + opName(inst.getOpcode()) + ", " + typ.getRegisterA() + ")";
                    } else if (inst instanceof DexBackedInstruction11n) {
                        DexBackedInstruction11n typ = (DexBackedInstruction11n) inst;
                        instStr = "new ImmutableInstruction11n(" + opName(inst.getOpcode()) + ", " + typ.getRegisterA() + ", " + typ.getNarrowLiteral() + ")";
                    } else if (inst instanceof DexBackedInstruction22t) {
                        DexBackedInstruction22t typ = (DexBackedInstruction22t) inst;
                        instStr = "new ImmutableInstruction22t(" + opName(inst.getOpcode()) + ", " + typ.getRegisterA() + ", " + typ.getRegisterB() + ", " + typ.getCodeOffset() + ")";
                    } else if (inst instanceof DexBackedInstruction10t) {
                        DexBackedInstruction10t typ = (DexBackedInstruction10t) inst;
                        instStr = "new ImmutableInstruction10t(" + opName(inst.getOpcode()) + ", " + typ.getCodeOffset() + ")";
                    } else if (inst instanceof DexBackedInstruction12x) {
                        DexBackedInstruction12x typ = (DexBackedInstruction12x) inst;
                        instStr = "new ImmutableInstruction12x(" + opName(inst.getOpcode()) + ", " + typ.getRegisterA() + ", " + typ.getRegisterB() + ")";
                    } else if (inst instanceof DexBackedInstruction21t) {
                        DexBackedInstruction21t typ = (DexBackedInstruction21t) inst;
                        instStr = "new ImmutableInstruction21t(" + opName(inst.getOpcode()) + ", " + typ.getRegisterA() + ", " + typ.getCodeOffset() + ")";
                    } else if (inst instanceof DexBackedInstruction23x) {
                        DexBackedInstruction23x typ = (DexBackedInstruction23x) inst;
                        instStr = "new ImmutableInstruction23x(" + opName(inst.getOpcode()) + ", " + typ.getRegisterA() + ", " + typ.getRegisterB() + ", " + typ.getRegisterC() + ")";
                    } else if (inst instanceof DexBackedInstruction21s) {
                        DexBackedInstruction21s typ = (DexBackedInstruction21s) inst;
                        instStr = "new ImmutableInstruction21s(" + opName(inst.getOpcode()) + ", " + typ.getRegisterA() + ", " + typ.getNarrowLiteral() + ")";
                    } else {
                        instStr = "EEEEEERRROOOOOOORRRRRRR unsuported instruction!";
                    }
                    instructions += instStr;
                    instrCtr++;
                }
                if (instrCtr > 0)
                    instructions = "List<ImmutableInstruction> instructions" + methodCtr + " = Arrays.asList(" + instructions + ");";
                else
                    instructions = "List<ImmutableInstruction> instructions" + methodCtr + " = null;";


                String methodimpl = "ImmutableMethodImplementation methodImplementation" + methodCtr + " = new ImmutableMethodImplementation(" + impl.getRegisterCount() + ", instructions" + methodCtr + ", null, null);";

                String methodDef = "Method method" + methodCtr + " = new ImmutableMethod(\"" + m.getDefiningClass() + "\", \"" + m.getName() + "\", parameters" + methodCtr + ", \"" + m.getReturnType() + "\", " + m.getAccessFlags() + ", null, methodImplementation" + methodCtr + ");";
                output += "/*************** BEGIN method definition for " + m.getName() + " **********/\n";
                output += paramsDef + "\n";
                output += instructions + "\n";
                output += methodimpl + "\n";
                output += methodDef += "\n";
                output += "/*************** END method definition for " + m.getName() + " **********/\n";
                output += "\n";
                methodCtr++;
            }
        }
        return output;
    }

     boolean checkDexInjectedGeneric(DexBackedDexFile dexFile, String className)
     {
         boolean foundStaticInit = false;
         for (DexBackedClassDef dexClass : dexFile.getClasses()) {
             String type = dexClass.getType();
             if (type.equals(className)) {
                 //unity engine
                 for (DexBackedMethod m : dexClass.getDirectMethods()) {
                     String name = m.getName();
                     if (name.equals("<clinit>")) {
                         //found a static class initializer, can't add another, means it's probably already injected
                         //TODO: see if this can be modified to add the additional loadlibrary call
                         foundStaticInit = true;
                         break;
                     }
                 }
                 break;
             }
         }
         return foundStaticInit;
     }

     boolean checkDexInjected(DexBackedDexFile dexFile ) throws Exception
    {
        boolean foundStaticInit = false;
        for (DexBackedClassDef dexClass : dexFile.getClasses()) {
            String type = dexClass.getType();
            if (type.equals("Lcom/unity3d/player/UnityPlayerActivity;")) {
                //unity engine
                for (DexBackedMethod m : dexClass.getDirectMethods()) {
                    String name = m.getName();
                    if (name.equals("<clinit>")) {
                        //found a static class initializer, can't add another, means it's probably already injected
                        //TODO: see if this can be modified to add the additional loadlibrary call
                        foundStaticInit = true;
                        break;
                    }
                }
                break;
            }
        }
        return foundStaticInit;
    }

//this will have to be somewhere we have android context for the package manager
/*    String findMainActivityClass(PackageManager pm, String packageName) {

        String packageName = context.getPackageName();
        Intent launchIntent = context.getPackageManager().getLaunchIntentForPackage(packageName);
        String className = launchIntent.getComponent().getClassName();
    }*/

    public String findInjectClass(DexBackedDexFile dexFile) throws Exception {

        for (DexBackedClassDef dexClass : dexFile.getClasses()) {
            String type = dexClass.getType();
            if (type.equals("Lcom/unity3d/player/UnityPlayerActivity;")) {
                //unity engine
                return type;
            } else if (type.equals("Lcom/epicgames/ue4/GameActivity;")) {
                //unreal engine
                return type;
            }
        }
        return null;
    }


    private String doRef(Reference ref)
    {
        String refDef = "";
        if (ref instanceof DexBackedMethodReference) {
            DexBackedMethodReference dbr = ((DexBackedMethodReference)ref);
            String paramList = "";
            int ctr = 0;
            for (String x : dbr.getParameterTypes())
            {
                if (ctr > 0)
                    paramList = paramList + ", ";
                paramList = paramList + "\""+ x + "\"";
                ctr++;
            }
            if (ctr > 0)
            {
                paramList = "Arrays.asList(" + paramList + ")";
            } else
            {
                paramList = "null";
            }
             refDef = "new ImmutableMethodReference(\""+dbr.getDefiningClass()+"\", \""+dbr.getName()+"\", "+paramList+", \""+dbr.getReturnType()+"\")";
        }
        else if (ref instanceof DexBackedTypeReference) {
            DexBackedTypeReference ftr = (DexBackedTypeReference)ref;
            refDef = "new ImmutableTypeReference(\""+ftr.getType()+"\")";
        }
        else if (ref instanceof DexBackedFieldReference) {
            DexBackedFieldReference fr = (DexBackedFieldReference)ref;
            refDef = "new ImmutableFieldReference(\""+fr.getDefiningClass()+"\", \""+fr.getName()+"\", \""+fr.getType()+"\")";
        }
        else if (ref instanceof DexBackedStringReference) {
            DexBackedStringReference sr = (DexBackedStringReference)ref;
            refDef = "new ImmutableStringReference(\""+sr.getString()+"\")";
        }
        else {
            refDef = "EEEEEEEEEERRRRRRRRRRRRROOOOOOOOOOORRRRRRRRRRRRRR unsupported reference type";
        }

        return refDef;
    }


    public boolean injectDexGeneric (File classesDexFilename, File moddedOutputFilename, String modLibName, @Nullable String targetClass) throws Exception {
        DexBackedDexFile dexFile = DexFileFactory.loadDexFile(classesDexFilename, null);
        if (targetClass == null) {
            targetClass = findInjectClass(dexFile);
        }
        if (targetClass == null)
            throw new Exception("Could not find target class");
        if (checkDexInjectedGeneric(dexFile, targetClass)) {
            return false;
        }
        
        final String target = targetClass;
        final String mod = modLibName;
        DexRewriter rewriter = new DexRewriter(new RewriterModule() {

            @Nonnull
            @Override public Rewriter<ClassDef> getClassDefRewriter(@Nonnull Rewriters rewriters) {
                return new GenericInjectorRewriter(rewriters, target, mod);
            }
        });
        DexFile rewritten = rewriter.rewriteDexFile(dexFile);
        DexFileFactory.writeDexFile(moddedOutputFilename.getAbsolutePath(), rewritten);
        return true;
    }

    public boolean injectDex (File classesDexFilename, File moddedOutputFilename) throws Exception {
        DexBackedDexFile dexFile = DexFileFactory.loadDexFile(classesDexFilename, null);

        if (checkDexInjected(dexFile)) {
            return false;
        }
        DexRewriter rewriter = new DexRewriter(new RewriterModule() {

            @Nonnull
            @Override public Rewriter<ClassDef> getClassDefRewriter(@Nonnull Rewriters rewriters) {
                return new InjectorClassDefRewrite(rewriters);
            }
        });
        DexFile rewritten = rewriter.rewriteDexFile(dexFile);
        DexFileFactory.writeDexFile(moddedOutputFilename.getAbsolutePath(), rewritten);
        return true;
    }


}
