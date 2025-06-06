//#line 2 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the yahboomcar_laser package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __yahboomcar_laser__LASERTRACKERPIDCONFIG_H__
#define __yahboomcar_laser__LASERTRACKERPIDCONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace yahboomcar_laser
{
  class laserTrackerPIDConfigStatics;

  class laserTrackerPIDConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      virtual ~AbstractParamDescription() = default;

      virtual void clamp(laserTrackerPIDConfig &config, const laserTrackerPIDConfig &max, const laserTrackerPIDConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const laserTrackerPIDConfig &config1, const laserTrackerPIDConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, laserTrackerPIDConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const laserTrackerPIDConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, laserTrackerPIDConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const laserTrackerPIDConfig &config) const = 0;
      virtual void getValue(const laserTrackerPIDConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T laserTrackerPIDConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T laserTrackerPIDConfig::* field;

      virtual void clamp(laserTrackerPIDConfig &config, const laserTrackerPIDConfig &max, const laserTrackerPIDConfig &min) const override
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const laserTrackerPIDConfig &config1, const laserTrackerPIDConfig &config2) const override
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, laserTrackerPIDConfig &config) const override
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const laserTrackerPIDConfig &config) const override
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, laserTrackerPIDConfig &config) const override
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const laserTrackerPIDConfig &config) const override
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const laserTrackerPIDConfig &config, boost::any &val) const override
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      virtual ~AbstractGroupDescription() = default;

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, laserTrackerPIDConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, laserTrackerPIDConfig &top) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const override
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T PT::* field;
      std::vector<laserTrackerPIDConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(laserTrackerPIDConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("lin_Kp"==(*_i)->name){lin_Kp = boost::any_cast<double>(val);}
        if("lin_Ki"==(*_i)->name){lin_Ki = boost::any_cast<double>(val);}
        if("lin_Kd"==(*_i)->name){lin_Kd = boost::any_cast<double>(val);}
        if("ang_Kp"==(*_i)->name){ang_Kp = boost::any_cast<double>(val);}
        if("ang_Ki"==(*_i)->name){ang_Ki = boost::any_cast<double>(val);}
        if("ang_Kd"==(*_i)->name){ang_Kd = boost::any_cast<double>(val);}
        if("laserAngle"==(*_i)->name){laserAngle = boost::any_cast<int>(val);}
        if("ResponseDist"==(*_i)->name){ResponseDist = boost::any_cast<double>(val);}
        if("priorityAngle"==(*_i)->name){priorityAngle = boost::any_cast<int>(val);}
        if("switch"==(*_i)->name){switch = boost::any_cast<bool>(val);}
      }
    }

    double lin_Kp;
double lin_Ki;
double lin_Kd;
double ang_Kp;
double ang_Ki;
double ang_Kd;
int laserAngle;
double ResponseDist;
int priorityAngle;
bool switch;

    bool state;
    std::string name;

    
}groups;



//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double lin_Kp;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double lin_Ki;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double lin_Kd;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double ang_Kp;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double ang_Ki;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double ang_Kd;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int laserAngle;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double ResponseDist;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int priorityAngle;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool switch;
//#line 231 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("laserTrackerPIDConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const laserTrackerPIDConfig &__max__ = __getMax__();
      const laserTrackerPIDConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const laserTrackerPIDConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const laserTrackerPIDConfig &__getDefault__();
    static const laserTrackerPIDConfig &__getMax__();
    static const laserTrackerPIDConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const laserTrackerPIDConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void laserTrackerPIDConfig::ParamDescription<std::string>::clamp(laserTrackerPIDConfig &config, const laserTrackerPIDConfig &max, const laserTrackerPIDConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class laserTrackerPIDConfigStatics
  {
    friend class laserTrackerPIDConfig;

    laserTrackerPIDConfigStatics()
    {
laserTrackerPIDConfig::GroupDescription<laserTrackerPIDConfig::DEFAULT, laserTrackerPIDConfig> Default("Default", "", 0, 0, true, &laserTrackerPIDConfig::groups);
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.lin_Kp = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.lin_Kp = 10.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.lin_Kp = 1.5;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("lin_Kp", "double", 0, "Kp in PID", "", &laserTrackerPIDConfig::lin_Kp)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("lin_Kp", "double", 0, "Kp in PID", "", &laserTrackerPIDConfig::lin_Kp)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.lin_Ki = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.lin_Ki = 10.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.lin_Ki = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("lin_Ki", "double", 0, "Ki in PID", "", &laserTrackerPIDConfig::lin_Ki)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("lin_Ki", "double", 0, "Ki in PID", "", &laserTrackerPIDConfig::lin_Ki)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.lin_Kd = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.lin_Kd = 10.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.lin_Kd = 2.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("lin_Kd", "double", 0, "Kd in PID", "", &laserTrackerPIDConfig::lin_Kd)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("lin_Kd", "double", 0, "Kd in PID", "", &laserTrackerPIDConfig::lin_Kd)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ang_Kp = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ang_Kp = 10.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ang_Kp = 1.5;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("ang_Kp", "double", 0, "Kp in PID", "", &laserTrackerPIDConfig::ang_Kp)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("ang_Kp", "double", 0, "Kp in PID", "", &laserTrackerPIDConfig::ang_Kp)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ang_Ki = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ang_Ki = 10.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ang_Ki = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("ang_Ki", "double", 0, "Ki in PID", "", &laserTrackerPIDConfig::ang_Ki)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("ang_Ki", "double", 0, "Ki in PID", "", &laserTrackerPIDConfig::ang_Ki)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ang_Kd = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ang_Kd = 10.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ang_Kd = 5.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("ang_Kd", "double", 0, "Kd in PID", "", &laserTrackerPIDConfig::ang_Kd)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("ang_Kd", "double", 0, "Kd in PID", "", &laserTrackerPIDConfig::ang_Kd)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.laserAngle = 10;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.laserAngle = 90;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.laserAngle = 65;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<int>("laserAngle", "int", 0, "laserAngle", "", &laserTrackerPIDConfig::laserAngle)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<int>("laserAngle", "int", 0, "laserAngle", "", &laserTrackerPIDConfig::laserAngle)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ResponseDist = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ResponseDist = 8.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ResponseDist = 1.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("ResponseDist", "double", 0, "ResponseDist", "", &laserTrackerPIDConfig::ResponseDist)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<double>("ResponseDist", "double", 0, "ResponseDist", "", &laserTrackerPIDConfig::ResponseDist)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.priorityAngle = 10;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.priorityAngle = 50;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.priorityAngle = 30;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<int>("priorityAngle", "int", 0, "priorityAngle", "", &laserTrackerPIDConfig::priorityAngle)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<int>("priorityAngle", "int", 0, "priorityAngle", "", &laserTrackerPIDConfig::priorityAngle)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.switch = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.switch = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.switch = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<bool>("switch", "bool", 0, "switch in rosbot", "", &laserTrackerPIDConfig::switch)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(laserTrackerPIDConfig::AbstractParamDescriptionConstPtr(new laserTrackerPIDConfig::ParamDescription<bool>("switch", "bool", 0, "switch in rosbot", "", &laserTrackerPIDConfig::switch)));
//#line 246 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(laserTrackerPIDConfig::AbstractGroupDescriptionConstPtr(new laserTrackerPIDConfig::GroupDescription<laserTrackerPIDConfig::DEFAULT, laserTrackerPIDConfig>(Default)));
//#line 369 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<laserTrackerPIDConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<laserTrackerPIDConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<laserTrackerPIDConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    laserTrackerPIDConfig __max__;
    laserTrackerPIDConfig __min__;
    laserTrackerPIDConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const laserTrackerPIDConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static laserTrackerPIDConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &laserTrackerPIDConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const laserTrackerPIDConfig &laserTrackerPIDConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const laserTrackerPIDConfig &laserTrackerPIDConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const laserTrackerPIDConfig &laserTrackerPIDConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<laserTrackerPIDConfig::AbstractParamDescriptionConstPtr> &laserTrackerPIDConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<laserTrackerPIDConfig::AbstractGroupDescriptionConstPtr> &laserTrackerPIDConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const laserTrackerPIDConfigStatics *laserTrackerPIDConfig::__get_statics__()
  {
    const static laserTrackerPIDConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = laserTrackerPIDConfigStatics::get_instance();

    return statics;
  }


}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __LASERTRACKERPIDRECONFIGURATOR_H__
