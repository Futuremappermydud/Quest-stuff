package com.emulamer.installerhelper;

import com.sun.istack.internal.NotNull;
import org.jf.dexlib2.Opcode;
import org.jf.dexlib2.iface.Annotation;
import org.jf.dexlib2.iface.ClassDef;
import org.jf.dexlib2.iface.Method;
import org.jf.dexlib2.iface.MethodParameter;
import org.jf.dexlib2.immutable.ImmutableMethod;
import org.jf.dexlib2.immutable.ImmutableMethodImplementation;
import org.jf.dexlib2.immutable.ImmutableMethodParameter;
import org.jf.dexlib2.immutable.instruction.ImmutableInstruction;
import org.jf.dexlib2.immutable.instruction.*;
import org.jf.dexlib2.immutable.instruction.ImmutableInstruction21c;
import org.jf.dexlib2.immutable.instruction.ImmutableInstruction35c;
import org.jf.dexlib2.immutable.instruction.ImmutableInstructionFactory;
import org.jf.dexlib2.immutable.reference.ImmutableMethodReference;
import org.jf.dexlib2.immutable.reference.*;
import org.jf.dexlib2.rewriter.ClassDefRewriter;
import org.jf.dexlib2.rewriter.RewriterUtils;
import org.jf.dexlib2.rewriter.Rewriters;
import org.jf.dexlib2.writer.InstructionFactory;
import org.jf.dexlib2.writer.builder.BuilderAnnotationSet;

import javax.annotation.Nonnull;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Set;

public class InjectorClassDefRewrite extends ClassDefRewriter
{
    public InjectorClassDefRewrite( Rewriters rewriters) {
        super(rewriters);

    }
    @Override
    public ClassDef rewrite(ClassDef classDef) {
        return new InjectorRewrittenClassDef(classDef);
    }

    protected class InjectorRewrittenClassDef extends RewrittenClassDef
    {
        public InjectorRewrittenClassDef(ClassDef classdef) {
            super(classdef);
        }

        @Override
        public Iterable<? extends Method> getVirtualMethods() {
            if (!classDef.getType().equals("Lcom/unity3d/player/UnityPlayerActivity;"))
                return super.getVirtualMethods();
            List<Method> methods = new ArrayList<Method>();


/*************** BEGIN method definition for onRequestPermissionsResult **********/
            List<ImmutableMethodParameter> parameters13 = Arrays.asList(new ImmutableMethodParameter("I", (Set<? extends Annotation >)null,"requestCode"), new ImmutableMethodParameter("[Ljava/lang/String;",(Set<? extends Annotation >)null,"permissions"), new ImmutableMethodParameter("[I", (Set<? extends Annotation >)null,"grantResults"));
            List<ImmutableInstruction> instructions13 = Arrays.asList(new ImmutableInstruction35c(Opcode.INVOKE_SUPER, 4,2, 3, 4, 5, 0, new ImmutableMethodReference("Landroid/app/Activity;", "onRequestPermissionsResult", Arrays.asList("I", "[Ljava/lang/String;", "[I"), "V")), new ImmutableInstruction12x(Opcode.ARRAY_LENGTH, 0, 5), new ImmutableInstruction11n(Opcode.CONST_4, 1, 0), new ImmutableInstruction21t(Opcode.IF_LEZ, 0, 10), new ImmutableInstruction23x(Opcode.AGET, 0, 5, 1), new ImmutableInstruction21t(Opcode.IF_NEZ, 0, 6), new ImmutableInstruction35c(Opcode.INVOKE_DIRECT, 1,2, 0, 0, 0, 0, new ImmutableMethodReference("Lcom/unity3d/player/UnityPlayerActivity;", "continueLoad", (Iterable<? extends CharSequence>)null, "V")), new ImmutableInstruction10t(Opcode.GOTO, 4), new ImmutableInstruction35c(Opcode.INVOKE_STATIC, 1,1, 0, 0, 0, 0, new ImmutableMethodReference("Ljava/lang/System;", "exit", Arrays.asList("I"), "V")), new ImmutableInstruction10x(Opcode.RETURN_VOID));
            ImmutableMethodImplementation methodImplementation13 = new ImmutableMethodImplementation(6, instructions13, null, null);
            Method method13 = new ImmutableMethod("Lcom/unity3d/player/UnityPlayerActivity;", "onRequestPermissionsResult", parameters13, "V", 1, null, methodImplementation13);
/*************** END method definition for onRequestPermissionsResult **********/
            methods.add(method13);

            for (Method m : this.classDef.getVirtualMethods())
            {
                String mName = m.getName();
                if (mName.equals("onStart"))
                {
                    /*************** BEGIN method definition for onStart **********/
                    List<ImmutableMethodParameter> parameters15 = null;
                    List<ImmutableInstruction> instructions15 = Arrays.asList(new ImmutableInstruction35c(Opcode.INVOKE_SUPER, 1,2, 0, 0, 0, 0, new ImmutableMethodReference("Landroid/app/Activity;", "onStart", (Iterable<? extends CharSequence>)null, "V")), new ImmutableInstruction21c(Opcode.CONST_STRING, 0, new ImmutableStringReference("android.permission.WRITE_EXTERNAL_STORAGE")), new ImmutableInstruction35c(Opcode.INVOKE_VIRTUAL, 2,2, 0, 0, 0, 0, new ImmutableMethodReference("Lcom/unity3d/player/UnityPlayerActivity;", "checkSelfPermission", Arrays.asList("Ljava/lang/String;"), "I")), new ImmutableInstruction11x(Opcode.MOVE_RESULT, 1), new ImmutableInstruction21t(Opcode.IF_NEZ, 1, 6), new ImmutableInstruction35c(Opcode.INVOKE_DIRECT, 1,2, 0, 0, 0, 0, new ImmutableMethodReference("Lcom/unity3d/player/UnityPlayerActivity;", "continueLoad", (Iterable<? extends CharSequence>)null, "V")), new ImmutableInstruction10t(Opcode.GOTO, 9), new ImmutableInstruction35c(Opcode.FILLED_NEW_ARRAY, 1,0, 0, 0, 0, 0, new ImmutableTypeReference("[Ljava/lang/String;")), new ImmutableInstruction11x(Opcode.MOVE_RESULT_OBJECT, 0), new ImmutableInstruction11n(Opcode.CONST_4, 1, 1), new ImmutableInstruction35c(Opcode.INVOKE_VIRTUAL, 3,2, 0, 1, 0, 0, new ImmutableMethodReference("Lcom/unity3d/player/UnityPlayerActivity;", "requestPermissions", Arrays.asList("[Ljava/lang/String;", "I"), "V")), new ImmutableInstruction10x(Opcode.RETURN_VOID));
                    ImmutableMethodImplementation methodImplementation15 = new ImmutableMethodImplementation(3, instructions15, null, null);
                    Method method15 = new ImmutableMethod("Lcom/unity3d/player/UnityPlayerActivity;", "onStart", parameters15, "V", 4, null, methodImplementation15);
                    /*************** END method definition for onStart **********/
                    methods.add(method15);
                } else {
                    methods.add(m);
                }
            }
            return methods;
        }

        @Override
        public Iterable<? extends Method> getDirectMethods()
        {
            if (!classDef.getType().equals("Lcom/unity3d/player/UnityPlayerActivity;"))
                return super.getDirectMethods();

            List<Method> methods = new ArrayList<Method>();
            int accessFlags = 65544;
            BuilderAnnotationSet annotations = null;
            String definingClass = "Lcom/unity3d/player/UnityPlayerActivity;";
            String name = "<clinit>";
            Iterable<MethodParameter> parameters = new ArrayList<MethodParameter>();
            String returnType = "V";
            ImmutableMethodParameter parameter = new ImmutableMethodParameter("Ljava/lang/String;",(Set<? extends Annotation>)null,null);
            List<ImmutableInstruction> instructions = Arrays.asList(
                    new ImmutableInstruction21c(Opcode.CONST_STRING, 0, new ImmutableStringReference("modloader")),
                    new ImmutableInstruction35c(Opcode.INVOKE_STATIC, 1, 0, 0, 0, 0, 0, new ImmutableMethodReference("Ljava/lang/System;", "loadLibrary", Arrays.asList(parameter), "V")),
                    new ImmutableInstruction10x(Opcode.RETURN_VOID)
            );


            ImmutableMethodImplementation methodImplementation = new ImmutableMethodImplementation(
                    1, instructions, null, null);

            Method staticInit = new ImmutableMethod(definingClass, name, parameters, returnType, accessFlags, annotations,
                    methodImplementation);
            methods.add(staticInit);

            /*************** BEGIN method definition for continueLoad **********/
            List<ImmutableMethodParameter> parameters2 = null;
            List<ImmutableInstruction> instructions2 = Arrays.asList(new ImmutableInstruction22c(Opcode.IGET_OBJECT, 0, 1, new ImmutableFieldReference("Lcom/unity3d/player/UnityPlayerActivity;", "mUnityPlayer", "Lcom/unity3d/player/UnityPlayer;")), new ImmutableInstruction35c(Opcode.INVOKE_VIRTUAL, 1,0, 0, 0, 0, 0, new ImmutableMethodReference("Lcom/unity3d/player/UnityPlayer;", "start", (Iterable<? extends CharSequence>)null, "V")), new ImmutableInstruction10x(Opcode.RETURN_VOID));
            ImmutableMethodImplementation methodImplementation2 = new ImmutableMethodImplementation(2, instructions2, null, null);
            Method method2 = new ImmutableMethod("Lcom/unity3d/player/UnityPlayerActivity;", "continueLoad", parameters2, "V", 2, null, methodImplementation2);
            /*************** END method definition for continueLoad **********/
            methods.add(method2);


            for (Method m : this.classDef.getDirectMethods())
            {
                methods.add(m);
            }
            return methods;
        }
    }
}