// see License.txt for copyright and terms of use

// Static Printer: A sample Oink tool that shows how to query the AST
// and typesystem; for now it just prints the inheritance graph.  If
// there is something you always wanted a tool to tell you about your
// raw program, implement it as feature here and send it to me.

#ifndef BULLET_H
#define BULLET_H

#include "oink.h"
#include "cc_ast_aux.h"         // LoweredASTVisitor

// LLVM headers need these
#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS

#include <llvm/Module.h>

class Bullet : public virtual Oink {
  // tor ****
  public:
  Bullet() {}
  
  // methods ****
//   void printIhg_stage();
  void emit_stage();
  void printASTHistogram_stage();
};

class CodeGenASTVisitor : public ASTVisitor {
  llvm::Function* currentFunction;
  llvm::BasicBlock *currentBlock;
  llvm::Value* lastValue;

  public:
  llvm::Module *mod;
  LoweredASTVisitor loweredVisitor; // use this as the argument for traverse()

  int num_TranslationUnit;
  int num_TopForm;
  int num_Function;
  int num_MemberInit;
  int num_Declaration;
  int num_ASTTypeId;
  int num_PQName;
  int num_TypeSpecifier;
  int num_BaseClassSpec;
  int num_Enumerator;
  int num_MemberList;
  int num_Member;
  int num_Declarator;
  int num_IDeclarator;
  int num_ExceptionSpec;
  int num_OperatorName;
  int num_Statement;
  int num_Condition;
  int num_Handler;
  int num_Expression;
  int num_FullExpression;
  int num_ArgExpression;
  int num_ArgExpressionListOpt;
  int num_Initializer;
  int num_TemplateDeclaration;
  int num_TemplateParameter;
  int num_TemplateArgument;
  int num_NamespaceDecl;
  int num_FullExpressionAnnot;
  int num_ASTTypeof;
  int num_Designator;
  int num_AttributeSpecifierList;
  int num_AttributeSpecifier;
  int num_Attribute;

  CodeGenASTVisitor();
  virtual ~CodeGenASTVisitor() {}

  void printHistogram(std::ostream &out);

  virtual bool visitTranslationUnit(TranslationUnit *obj);
  virtual void postvisitTranslationUnit(TranslationUnit *obj);
  virtual bool visitTopForm(TopForm *obj);
  virtual void postvisitTopForm(TopForm *obj);
  virtual bool visitFunction(Function *obj);
  virtual void postvisitFunction(Function *obj);
  virtual bool visitMemberInit(MemberInit *obj);
  virtual void postvisitMemberInit(MemberInit *obj);
  virtual bool visitDeclaration(Declaration *obj);
  virtual void postvisitDeclaration(Declaration *obj);
  virtual bool visitASTTypeId(ASTTypeId *obj);
  virtual void postvisitASTTypeId(ASTTypeId *obj);
  virtual bool visitPQName(PQName *obj);
  virtual void postvisitPQName(PQName *obj);
  virtual bool visitTypeSpecifier(TypeSpecifier *obj);
  virtual void postvisitTypeSpecifier(TypeSpecifier *obj);
  virtual bool visitBaseClassSpec(BaseClassSpec *obj);
  virtual void postvisitBaseClassSpec(BaseClassSpec *obj);
  virtual bool visitEnumerator(Enumerator *obj);
  virtual void postvisitEnumerator(Enumerator *obj);
  virtual bool visitMemberList(MemberList *obj);
  virtual void postvisitMemberList(MemberList *obj);
  virtual bool visitMember(Member *obj);
  virtual void postvisitMember(Member *obj);
  virtual bool visitDeclarator(Declarator *obj);
  virtual void postvisitDeclarator(Declarator *obj);
  virtual bool visitIDeclarator(IDeclarator *obj);
  virtual void postvisitIDeclarator(IDeclarator *obj);
  virtual bool visitExceptionSpec(ExceptionSpec *obj);
  virtual void postvisitExceptionSpec(ExceptionSpec *obj);
  virtual bool visitOperatorName(OperatorName *obj);
  virtual void postvisitOperatorName(OperatorName *obj);
  virtual bool visitStatement(Statement *obj);
  virtual void postvisitStatement(Statement *obj);
  virtual bool visitCondition(Condition *obj);
  virtual void postvisitCondition(Condition *obj);
  virtual bool visitHandler(Handler *obj);
  virtual void postvisitHandler(Handler *obj);
  virtual bool visitExpression(Expression *obj);
  virtual void postvisitExpression(Expression *obj);
  virtual bool visitFullExpression(FullExpression *obj);
  virtual void postvisitFullExpression(FullExpression *obj);
  virtual bool visitArgExpression(ArgExpression *obj);
  virtual void postvisitArgExpression(ArgExpression *obj);
  virtual bool visitArgExpressionListOpt(ArgExpressionListOpt *obj);
  virtual void postvisitArgExpressionListOpt(ArgExpressionListOpt *obj);
  virtual bool visitInitializer(Initializer *obj);
  virtual void postvisitInitializer(Initializer *obj);
  virtual bool visitTemplateDeclaration(TemplateDeclaration *obj);
  virtual void postvisitTemplateDeclaration(TemplateDeclaration *obj);
  virtual bool visitTemplateParameter(TemplateParameter *obj);
  virtual void postvisitTemplateParameter(TemplateParameter *obj);
  virtual bool visitTemplateArgument(TemplateArgument *obj);
  virtual void postvisitTemplateArgument(TemplateArgument *obj);
  virtual bool visitNamespaceDecl(NamespaceDecl *obj);
  virtual void postvisitNamespaceDecl(NamespaceDecl *obj);
  virtual bool visitFullExpressionAnnot(FullExpressionAnnot *obj);
  virtual void postvisitFullExpressionAnnot(FullExpressionAnnot *obj);
  virtual bool visitASTTypeof(ASTTypeof *obj);
  virtual void postvisitASTTypeof(ASTTypeof *obj);
  virtual bool visitDesignator(Designator *obj);
  virtual void postvisitDesignator(Designator *obj);
  virtual bool visitAttributeSpecifierList(AttributeSpecifierList *obj);
  virtual void postvisitAttributeSpecifierList(AttributeSpecifierList *obj);
  virtual bool visitAttributeSpecifier(AttributeSpecifier *obj);
  virtual void postvisitAttributeSpecifier(AttributeSpecifier *obj);
  virtual bool visitAttribute(Attribute *obj);
  virtual void postvisitAttribute(Attribute *obj);
};

#endif // BULLET_H
